#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
#include "lbyec2b.h"

typedef struct tm Datetime;

typedef struct EpiData {
    char CaseCode[256];
    int Age;
    char AgeGroup[256];
    char Sex[256];
    Datetime DateSpecimen;
    Datetime DateResultRelease;
    Datetime DateRepConf;
    Datetime DateDied;
    Datetime DateRecover;
    char RemovalType[256];
    int Admitted;
    char RegionRes[256];
    char ProvRes[256];
    char CityMunRes[256];
    char CityMuniPSGC[256];
    char BarangayRes[256];
    char BarangayPSGC[256];
    char HealthStatus[256];
    int Quarantined;
    Datetime DateOnset;
    char Pregnanttab[256];
} EpiData;

typedef struct Case {
    long confirmed;
    long active;
    long recovered;
    long died;
} Case;

long countDiedByAgeGroup(EpiData *report, char *agegroup, int N) {
    long count = 0;
    for (int i = 0; i < N; i++) {
        if (strcmp(report[i].AgeGroup, agegroup) == 0 && strcmp(report[i].HealthStatus, "Died") == 0) {
            count++;
        }
    }
    return count;
}

bool isDateEqual(Datetime src_date, Datetime target_date) {
    return (src_date.tm_year == target_date.tm_year &&
            src_date.tm_mon == target_date.tm_mon &&
            src_date.tm_mday == target_date.tm_mday);
}

double countRegionByPublishDate(EpiData *report, char *region, char *date, int N) {
    struct tm target_date = convertDate(date, 0, 0);
    double count = 0;
    for (int i = 0; i < N; i++) {
        if (strcmp(report[i].RegionRes, region) == 0 && isDateEqual(report[i].DateRepConf, target_date)) {
            count++;
        }
    }
    return count;
}

long countRegion(EpiData *report, char *region, int N) {
    long count = 0;
    for (int i = 0; i < N; i++) {
        if (strcmp(report[i].RegionRes, region) == 0) {
            count++;
        }
    }
    return count;
}

Case calcCases(EpiData *report, long N) {
    Case count = {0, 0, 0, 0};
    for (long i = 0; i < N; i++) {
        count.confirmed++;
        if (strcmp(report[i].HealthStatus, "Active") == 0) {
            count.active++;
        } else if (strcmp(report[i].HealthStatus, "Recovered") == 0) {
            count.recovered++;
        } else if (strcmp(report[i].HealthStatus, "Died") == 0) {
            count.died++;
        }
    }
    return count;
}

void analyzeData(EpiData *report, long N) {
    int choice = 0;
    char region[256], date[256], ageGroup[256];
    Case totalCount;
    long count = 0;
    printf("Analysis Options:\n");
    printf("1. Total Confirmed Case\n");
    printf("2. Total Case By Region\n");
    printf("3. Total Case on Region by Publish Date\n");
    printf("4. Total Death by Age Group\n");
    printf("5. Exit\n");
    do {
        printf("Choice: ");
        scanf("%d", &choice);
        if (choice == 1) {
            totalCount = calcCases(report, N);
            printf("Confirmed: %ld, Active: %ld, Recovered: %ld, Died: %ld\n", totalCount.confirmed, totalCount.active, totalCount.recovered, totalCount.died);
        } else if (choice == 2) {
            printf("Enter Region: ");
            scanf(" %[^\n]s", region);
            count = countRegion(report, region, N);
            printf("Total count on %s is %ld\n", region, count);
        } else if (choice == 3) {
            printf("Enter Region: ");
            scanf(" %[^\n]s", region);
            printf("Enter Date[YYYY-MM-DD]: ");
            scanf(" %[^\n]s", date);
            count = countRegionByPublishDate(report, region, date, N);
            printf("Total count on %s published on %s is %ld\n", region, date, count);
        } else if (choice == 4) {
            printf("Enter Age Group (e.g. 50 to 54): ");
            scanf(" %[^\n]s", ageGroup);
            count = countDiedByAgeGroup(report, ageGroup, N);
            printf("Total count for agegroup %s is %ld\n", ageGroup, count);
        }
    } while (choice != 5);
}

void processWord(char *word, int rowNum, int columnNum, EpiData *row) {
    switch (columnNum) {
        case 0: strcpy(row->CaseCode, word); break;
        case 1: row->Age = atoi(word); break;
        case 2: strcpy(row->AgeGroup, word); break;
        case 3: strcpy(row->Sex, word); break;
        case 4: row->DateSpecimen = convertDate(word, rowNum, columnNum); break;
        case 5: row->DateResultRelease = convertDate(word, rowNum, columnNum); break;
        case 6: row->DateRepConf = convertDate(word, rowNum, columnNum); break;
        case 7: row->DateDied = convertDate(word, rowNum, columnNum); break;
        case 8: row->DateRecover = convertDate(word, rowNum, columnNum); break;
        case 9: strcpy(row->RemovalType, word); break;
        case 10: row->Admitted = atoi(word); break;
        case 11: strcpy(row->RegionRes, word); break;
        case 12: strcpy(row->ProvRes, word); break;
        case 13: strcpy(row->CityMunRes, word); break;
        case 14: strcpy(row->CityMuniPSGC, word); break;
        case 15: strcpy(row->BarangayRes, word); break;
        case 16: strcpy(row->BarangayPSGC, word); break;
        case 17: strcpy(row->HealthStatus, word); break;
        case 18: row->Quarantined = atoi(word); break;
        case 19: row->DateOnset = convertDate(word, rowNum, columnNum); break;
        case 20: strcpy(row->Pregnanttab, word); break;
        default: break;
    }
}

long loadCSV(char filename[], char directory[], EpiData *report) {
    FILE *fp;
    char buffer[2048];
    char word[2048];
    char token_pos = 0;
    int record_count = 0;
    int field_count = 0;
    char *path;
    path = malloc((strlen(filename) + strlen(directory) + 2) * sizeof(char));
    strcpy(path, directory);
    strcat(path, "/");
    strcat(path, filename);
    fp = fopen(path, "r");

    if (!fp) {
        printf("Error reading CSV File. Make sure filename is correct.\n");
        free(path);
        return 0;
    }

    int isHeader = 1;
    while (fgets(buffer, 2048, fp)) {
        if (isHeader) {
            isHeader = 0;
            continue;
        }

        field_count = 0;
        int i = 0;
        int isquote = 0;
        do {
            word[token_pos] = buffer[i];
            token_pos++;

            if (!isquote && (buffer[i] == ',' || buffer[i] == '\n')) {
                word[token_pos - 1] = 0;
                token_pos = 0;
                processWord(word, record_count, field_count, report);
                field_count++;
            }

            if (buffer[i] == '"' && buffer[i + 1] != '"') {
                isquote = !isquote;
                token_pos--;
            }

            if (buffer[i] == '"' && buffer[i + 1] == '"') {
                i++;
            }

            i++;
        } while (buffer[i]);

        record_count++;
        report++;
    }

    fclose(fp);
    free(path);
    return record_count;
}

int main(void) {
    EpiData *report;
    report = (EpiData *)malloc(1000000 * sizeof(EpiData));

    long total = loadCSV("Case-Information.csv", "assets", report);

    if (total == 0) {
        printf("No records loaded. Exiting.\n");
        free(report);
        return 1;
    }

    analyzeData(report, total);

    free(report);

    return 0;
}
