[![Open in Codespaces](https://classroom.github.com/assets/launch-codespace-7f7980b617ed060a017424585567c406b6ee15c891e84e1186181d67ecf80aa0.svg)](https://classroom.github.com/open-in-codespaces?assignment_repo_id=15177944)
# Laboratory Activity 3 Homework - Structures

## Getting Started

Before you start reading the homework, make sure to do the ff:
- Download the copy of your Github repository into the same way as in previous exercises
- Afterward, download CSV Data in [Google Drive](https://drive.google.com/file/d/1Z-4ZKALjfPP5SVsnedq80DfsW8NLx3FK/view?usp=sharing).
- Open Windows Explorer/ Finder, then move the CSV file into the "assets" folder. 
    -  Under the "assets" folder, make sure the CSV filename is **identical** to "Case-Information.csv"
    - *Inappropriate* filename includes but not limited to:  "case-information.csv","Case-Information (1).csv", "Copy of Case-Information.csv", etc.

## COVID-19 Tracker

One of your uncles, who's working under the Department of Health, learned that you're taking up a programming class. So, you've been asked if you can replicate their current COVID tracker. This is his mini-test if you can help him on creating automated data analytics.

Develop a program that will replicate the [COVID19 Tracker by DOH](https://doh.gov.ph/diseases/covid-19/covid-19-case-tracker/)

You are provided with the official January 3, 2024, Data Drop from DOH in CSV format (CSV is discussed in the next subsection) On the said spreadsheet, your program should have the ff analytics functionality:

1. Total Number of Cases: (a) Confirmed, (b) Active, (c) Recovered, (d) Death
2. Total Confirmed Cases by Region
3. Total Confirmed Cases by Region and Published Date
4. Total Confirmed Cases by Age Group

| Sample Console Input                  | Expected Console Output                                                                                                                                                                                                                                                                                  |
| ------------------------------------- | -------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| 1<br>5                                | Analysis Options:<br>1. Total Confirmed Case<br> 2. Total Case By Region<br> 3. Total Case on Region by Publish Date<br> 4. Total Death by Age Group<br>5. Exit<br>Choice: 1<br>Confirmed: 136488, Active: 1562, Recovered: 134457, Died: 469<br>Choice: 5                                              |
| 2<br>NCR<br>5                         | Analysis Options:<br>1. Total Confirmed Case<br> 2. Total Case By Region<br> 3. Total Case on Region by Publish Date<br> 4. Total Death by Age Group<br>5. Exit<br>Choice: 2<br>Type Region: NCR<br>Total count on NCR is 46000<br>Choice: 5                                                             |
| 2<br>Region VII<br>5                  | Analysis Options:<br>1. Total Confirmed Case<br> 2. Total Case By Region<br> 3. Total Case on Region by Publish Date<br> 4. Total Death by Age Group<br>5. Exit<br>Choice: 2<br>Type Region: Region VII<br>Total count on Region VII is 0<br>Choice: 5                                                   |
| 2<br>Region VII: Central Visayas<br>5 | Analysis Options:<br>1. Total Confirmed Case<br> 2. Total Case By Region<br> 3. Total Case on Region by Publish Date<br> 4. Total Death by Age Group<br>5. Exit<br>Choice: 2<br>Type Region: Region VII: Central Visayas<br>Total count on Region VII: Central Visayas is 4595<br>Choice: 5             |
| 3<br>NCR<br>2023-01-11<br>5           | Analysis Options:<br>1. Total Confirmed Case<br> 2. Total Case By Region<br> 3. Total Case on Region by Publish Date<br> 4. Total Death by Age Group<br>5. Exit<br>Choice: 3<br>Type Region: NCR<br>Type Date[YYYY-MM-DD]: 2023-01-11<br>Total count on NCR published on 2023-01-11 is 92<br>Choice: 5 |
| 3<br>NCR<br>2023-12-01<br>5           | Analysis Options:<br>1. Total Confirmed Case<br> 2. Total Case By Region<br> 3. Total Case on Region by Publish Date<br> 4. Total Death by Age Group<br>5. Exit<br>Choice: 3<br>Type Region: NCR<br>Type Date[YYYY-MM-DD]: 2023-12-01<br>Total count on NCR published on 2023-12-01 is 72<br>Choice: 5    |
| 3<br>CAR<br>2023-06-01<br>5           | Analysis Options:<br>1. Total Confirmed Case<br> 2. Total Case By Region<br> 3. Total Case on Region by Publish Date<br> 4. Total Death by Age Group<br>5. Exit<br>Choice: 3<br>Type Region: CAR<br>Type Date[YYYY-MM-DD]: 2023-06-01<br>Total count on CAR published on 2023-06-01 is 48<br>Choice: 5    |
| 4<br>30 to 34<br>5                    | Analysis Options:<br>1. Total Confirmed Case<br> 2. Total Case By Region<br> 3. Total Case on Region by Publish Date<br> 4. Total Death by Age Group<br>5. Exit<br>Choice: 4<br>Enter Age Group (e.g. 50 to 54): 30 to 34<br>Total count for agegroup 30 to 34 is 17<br>Choice: 5                       |
| 4<br>60 to 64<br>5                    | Analysis Options:<br>1. Total Confirmed Case<br> 2. Total Case By Region<br> 3. Total Case on Region by Publish Date<br> 4. Total Death by Age Group<br>5. Exit<br>Choice: 4<br>Enter Age Group (e.g. 50 to 54): 60 to 64<br>Total count for agegroup 60 to 64 is 52<br>Choice: 5                       |
| 4<br>85 to 89<br>5                    | Analysis Options:<br>1. Total Confirmed Case<br> 2. Total Case By Region<br> 3. Total Case on Region by Publish Date<br> 4. Total Death by Age Group<br>5. Exit<br>Choice: 4<br>Enter Age Group (e.g. 50 to 54): 85 to 89<br>Total count for agegroup 85 to 89 is 0<br>Choice: 5                         |

## What is a CSV?

CSV stands for Comma Separated Value. It is a simple file format standard to create a "spreadsheet". So you can think of CSV as a spreadsheet. CSV files can be read by Microsoft Excel! However, do not edit and save CSV files opened by excel as this will ruin the formatting of the original CSV.

### How does it work? 
Well, in its basic form, it follows the ff:
- one line in a CSV is one row.
- Each column shall be separated by a comma.
- You'll know that it is the end of the row when it sees a newline(aka \n).
- The next line is considered a new row. Perform the same operation as above to get a separate column.

For example, you wrote the ff lines in a notepad, and save it as sample1.csv:
ID Number, Name, email
11022222, John Anthony Jose, john.anthony.jose@dlsu.edu.ph
12012345, Rafael Palma, rafael.palma@up.edu.ph

This file can automatically be read by Excel as follows:

| ID Number | Name              | Email                         |
| --------- | ----------------- | ----------------------------- |
| 11022222  | John Anthony Jose | john.anthony.jose@dlsu.edu.ph |
| 12012345  | Rafael Palma      | rafael.palma@up.edu.ph        |

### Dealing with the comma in a "Column"
What if you have a comma inside a column? For example Taft. Ave, Manila?

To solve this issue, any text enclosed in a double quote is considered one column, regardless if it has a comma inside or not. Let's show it by example:

Save the ff as sample2.csv:   
ID Number, Name, email, address  
11022222, John Anthony Jose, john.anthony.jose@dlsu.edu.ph, "Taft Ave., Manila"  
12012345, Rafael Palma, rafael.palma@up.edu.ph, "Diliman, Quezon City"

This file will be read by Excel as shown below. Observe that the Taft Ave and Manila are not split into separate columns.

| ID Number | Name | Email | Address |
| --------- | ----------------- | ----------------------------- | -------------------- |
| 11022222 | John Anthony Jose | john.anthony.jose@dlsu.edu.ph | Taft Ave., Manila |
| 12012345 | Rafael Palma | rafael.palma@up.edu.ph | Diliman, Quezon City |

## Task 0: Parsing CSV into the proper Data Type

The first task you want to do is to complete the loading of CSV data into the right form of a structure array. The CSV file is already provided to you. It's located under the **assets** folder. This data came from Case Information Table from the DOH website dated August 04, 2020.

In this task, you would complete the structure `EpiData` as shown below. `EpiData` defines the columns/fields we expect to get from the CSV. You can refer to the MetaData section as shown in the subsequent subsection. The MetaData section already shows the column in its correct column sequence. Alternatively, you can browse the CSV file using either notepad or Excel.

```C
typedef struct EpiData
{

} EpiData;
```

Note:
- Make sure that you provide the right data type. 
- Since our confirmed cases have breached the max limit of `int`, which is 32,767, please do not declare variables of int as int. Rather, please use the longer one called `long`. It's the same as int but rather has a bigger capacity.
- Similarly, if you need a decimal number, use `double` rather than `float`.
- Lastly, if you need to declare the variable as a string, my recommendation is to declare it with a maximum length of 256.

When you are done, C doesn't know how to read a CSV-formatted file. Thus, we will need to write the code on how to read a CSV properly. Fortunately, you have been provided with the complete `loadCSV()` function such that it will be able to read and convert CSV-formatted files into the proper structure array. Please study the implementation of how to read a CSV file.

Unfortunately, different CSV files contain different columns, so you still need to complete the `processWord()` function as shown below:

```Cpp
void processWord(char *word, int rowNum, int columnNum, EpiData *row)
```

The `loadCSV()` function is dependent on `processWord()` to work properly. `processWord()` function is responsible for converting the string into the right data type. You might ask why do we need to do this. It's because the `loadCSV()` reads a CSV file as an array of characters (aka. string). However, we want to convert it into the right data type so that we will be able to use it in our analysis of our later tasks.

To convert a string into the right data type, some utility functions are provided inside `lbyec2b.h`. Make sure to read its accompanying documentation on how they work.


```c
long convertLong(char *word, int rowNum, int columnNum)
```

```c
double convertDouble(char *word, int rowNum, int columnNum)
```

```Cpp
struct tm convertDatetime(char *word, int rowNum, int columnNum)
```

```Cpp
struct tm convertDate(char *word, int rowNum, int columnNum)
```

Note:
- The result of the conversion should be stored at `row` variable.
- Think of each element of the structure array as the row of our table
- Think of the variables you've declared in the structure as the column/field
- Therefore, `row` variable is already pointing to the row of our table

If you are pointing to a structure, you do it by:
```C
(*row).columnName = you_write_something_here;
```

Don't forget the parenthesis above! Otherwise, you will encounter errors.  
Alternatively, as a shorthand notation, you can do:

```C
row->columnName = you_write_something_here;
```

The two codes are just equivalent to each other.

Lastly, please make sure that the `processWord()` converts all columns of the CSV. This is easy because `loadCSV()` will call `processWord()` in every column on each row. Thus, you only need to include some conditional statements like If/Elseif/Else or Switch/Case Statements inside `processWord()`.

## Task 1: Total Cases

Before you start at task 1, observe that the required prompt is already provided to you:

```C
void analyzeData(EpiData *report, long N)
```

Study `analyzeData()` function on how it was called by the `main()`. In addition, inside `analyzeData()`, study which functions are being called for each type of analysis.

For this task, you will need to complete `calcCases()` function:

```C
Case calcCases(EpiData *report, long N)
```

Here are some tips for each type of covid case:

Confirmed Cases = As we are using the Case Information Table from DOH, each row is already the confirmed COVID cases in the Philippines since the start of COVID.

Active Cases = You can use the column HealthStatus to check whether it's active or not

Died Cases = You can use the column HealthStatus to check whether the patient died or not.

Note: `Case` Structure is already provided to you:

```C
typedef struct Case
{
    long confirmed;
    long active;
    long recovered;
    long died;
} Case;
```

Hint:

- Which function do you use to compare two strings? (i.e. strcmp)
- How do you count items in a loop? (i.e. create a counter)

## Task 2: Total Case by Region

In this task, you need to complete the function:

```C
long countRegion(EpiData *report, char *region, int N)
```

You can easily do it by iterating on each element (i.e. record) of our structure array `report` and get the region of each element. Given that you can get the record, just count how many of the records have the same location as the `region` variable?

Hint:
- Make sure that the region name you've entered is exactly the region name as stated in CSV file. For example, Region VII will return a result of zero. While Region VII: Central Visayas will show up some result
- On which column can you find the region of each record?
- Browse the CSV files so that you can check which region names are "valid" region names

## Task 3: Total Case on Region by Publish Date

In this task, you need to complete the function:

```cpp
double countRegionByPublishDate(EpiData *report, char *region, char *date, int N)
```

This task will require us to use of two filters on our count: (1) Region, and (2) Published Date. When we say publish date, this is the date when the case was publicly announced as a confirmed case (Hint: Which column is that?).

Moreover, recall that the date in the CSV file is provided to you as a string. Make sure that you convert it into the built-in [struct tm](http://www.cplusplus.com/reference/ctime/tm/) format. To do so, you can use `parseDate()` provided in `lbyec2b.h`

For you to compare two dates of [struct tm](http://www.cplusplus.com/reference/ctime/tm/), you need to complete the extra function:

```C
bool isDateEqual(Datetime src_date, Datetime target_date)
```

`isDateEqual` function will be useful to complete `countRegionByPublishDate` function.

Note: 
- This is not the same number that you will see on the DOH dashboard. DOH includes an additional post-processing operation (i.e. 7-day moving average).

Hint:

- Make sure to read the documentation of tm struct. It is useful to understand the fields it contains.
- To filter the regions, how do you compare two strings?
- How can you combine two conditions such that you will be able to count when BOTH conditions are true?

## Task 4: Total Death by Age Group

In this task, you will need to complete the function:

```C
long countDiedByAgeGroup(EpiData *report, char *agegroup, int N)
```

Note:
- assume that the user will enter a valid age group in a 5-year age group format as standardized by DOH data. Otherwise, if it's invalid, then the function returns a count of 0.

Hint:
- Rather than parsing `agegroup` into two separate age variables, given the assumption above, you think of `agegroup` as a string
- How can you compare two strings??? (i.e. strcmp)

## Metadata

Here's the metadata according to DOH

| Field             | Description                                                                                               | Type   |
| ----------------- | --------------------------------------------------------------------------------------------------------- | ------ |
| CaseCode          | Random code assigned for labelling cases; does not equate to the unique case number assigned by DOH       | Text   |
| Age               | Age                                                                                                       | Number |
| AgeGroup          | Five-year age group                                                                                       | Text   |
| Sex               | Sex                                                                                                       | Text   |
| DateSpecimen      | Date when specimen was collected                                                                          | Date   |
| DateResultRelease | Date of release of result                                                                                 | Date   |
| DateRepConf       | Date publicly announced as confirmed case                                                                 | Date   |
| DateDied          | Date died                                                                                                 | Date   |
| DateRecover       | Date recovered                                                                                            | Date   |
| RemovalType       | Type of removal (recovery or death)                                                                       | Text   |
| Admitted          | Binary variable indicating patient has been admitted to hospital                                          | Binary |
| RegionRes         | Region of residence                                                                                       | Text   |
| ProvRes           | Province of residence                                                                                     | Text   |
| CityMunRes        | City of residence                                                                                         | Text   |
| CityMuniPSGC      | Philippine Standard Geographic Code of Municipality or City of Residence                                  | Text   |
| BarangayRes       | Barangay of residence                                                                                     |        |
| BarangayPSGC      | Philippine Standard Geographic Code of Barangay of residence                                              |        |
| HealthStatus      | Known current health status of patient (asymptomatic, mild, moderate, severe, critical, died, recovered)  | Test   |
| Quarantined       | Ever been home quarantined, not necessarily currently in home quarantine                                  | Binary |
| DateOnset         | Date of Onset of Symptoms                                                                                 | Date   |
| Pregnanttab       | Yes/No if patient is pregnant at any point during COVID-19 condition                                      | Binary |
