#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define SizeLine 1024

struct Student{
    /* data */
    double GPA;
    int CriditHour;
    char *FirstName, *LastName, *Major, *Degree, *TA, *Advisor;
};

struct Student getAll(char* line){
    struct Student person;

    person.FirstName = strdup(strtok(line,","));
    person.LastName = strdup(strtok(NULL,","));
    person.Major = strdup(strtok(NULL,","));
    person.Degree = strdup(strtok(NULL,","));
    person.GPA = atof(strtok(NULL,","));
    person.CriditHour = atoi(strtok(NULL,","));
    person.TA = strdup(strtok(NULL,","));
    person.Advisor = strdup(strtok(NULL,","));

    return person;
}

void ShowStruct(struct Student person){
    printf("FirstName = %s\n", person.FirstName);
    printf("LastName = %s\n", person.LastName);
    printf("Major = %s\n",person.Major);
    printf("Degree = %s\n", person.Degree);
    printf("GPA = %f\n", person.GPA);
    printf("CriditHour = %d\n", person.CriditHour);
    printf("TA = %s\n", person.TA);
    printf("Advisor = %s\n\n", person.Advisor);
}


int main()
{
    struct Student GetPersons[100];
    char Line[SizeLine];
    int count;

    FILE *studentdata = NULL;
    studentdata = fopen("students_dataset.csv","r");
    if (studentdata == NULL)
        {
        printf("error in read\n");
        exit (-1);
        }

    count = 0;
    while (fgets(Line, SizeLine, studentdata) != NULL)
    {
        /* code */
        GetPersons[count++] = getAll(Line);
    }

    fclose(studentdata);

/*for (int i = 1; i < count; i++)
    {
        //code
        printf("Person %d Degree = %s\n",i,GetPersons[i].Degree);
    }
*/

    char uniqeDegree[10][100];
    //memset(uniqeDegree, '\0', sizeof(uniqeDegree));
    strcpy(uniqeDegree[0],GetPersons[1].Degree);
    //printf("uniqeDegree0 =  %s\n",uniqeDegree[0]);
    int flags = 0, countDegree = 1;
    int i,j;


    for (i = 1; i < count; i++)
    {
        flags = 0;
        for (j=0; j<10; j++)
        {
            //code
            if (strcmp(GetPersons[i].Degree,uniqeDegree[j]) != 0)
            {
                //printf("The Dif ----i= %d  j=%d\n",i,j);
                flags = 1;
            }
            else if (strcmp(GetPersons[i].Degree,uniqeDegree[j]) == 0)
            {
                //printf("The same ----i=%d  j=%d\norigDegree =  %s\nuniqeDegree=  %s\n>
                flags = 0;
                break;
            }

        }
        //printf("%d",flags);
        if (flags)
            {
                //code
                //printf("I'm in i= %d\n",i);
                strcpy(uniqeDegree[countDegree],GetPersons[i].Degree);
                //printf("!!!!%s\ncount = %d\n---------\n",uniqeDegree[countDegree],cou>
                strcpy(uniqeDegree[countDegree+1],"\0");
                countDegree++;
            }
    }


     printf("How many different degrees do we have?\n%d\n",countDegree);
    int q;
    for(q=0;q<countDegree;q++)
    {
        /* code */
        printf("%s\n",uniqeDegree[q]);
    }


    double FirstGPA,SecondGPA,ThirdGPA;
    int gpa_i;

    for(gpa_i = 1; gpa_i < count; gpa_i++){
           if(GetPersons[gpa_i].GPA > FirstGPA)
           {
            FirstGPA = GetPersons[gpa_i].GPA;
            continue;
           }
           else if (GetPersons[gpa_i].GPA > SecondGPA)
           {
            SecondGPA = GetPersons[gpa_i].GPA;
            continue;
           }
           else if (GetPersons[gpa_i].GPA > ThirdGPA)
           {
            ThirdGPA = GetPersons[gpa_i].GPA;
            continue;
           }
    }

     //printf("NO.1 = %f\nNO.2 = %f\nNO.2 = %f\n",FirstGPA,SecondGPA,ThirdGPA);

    //int GAPCmpcount[10];
    printf("\n3 students who have the highest GPA\n");
    for (int cmp = 1; cmp < count; cmp++)
    {
         if(GetPersons[cmp].GPA == FirstGPA)
           {
            //printf("First = %d\n",cmp);
            printf("Highest = %s %s\n",GetPersons[cmp].FirstName,GetPersons[cmp].LastName);
           }
        else if(GetPersons[cmp].GPA == SecondGPA)
           {
            //printf("Second = %d\n",cmp);
            printf("Second = %s %s\n",GetPersons[cmp].FirstName,GetPersons[cmp].LastName);
           }
        else if(GetPersons[cmp].GPA == ThirdGPA)
           {
            //printf("Third = %d\n",cmp);
            printf("Third = %s %s\n",GetPersons[cmp].FirstName,GetPersons[cmp].LastName);
           }

    }


    printf("\nAverage credit hours of the college\n");
    //printf("Cr%d\n",GetPersons[1].CriditHour);
    int CreditSum=0;
    double AvgCredit;
    for (int Cred= 1; Cred < count; Cred++)
    {
        CreditSum = CreditSum + GetPersons[Cred].CriditHour;
        //printf("Crsum = %d\n",CreditSum);
    }

    AvgCredit = (float)CreditSum/(count-1);

    printf("%f\n",AvgCredit);

    printf("\nAverage GPA of the students in Computer Science\n");
    int CScount[100];
    int CSget=0;
    //printf("%s",GetPersons[1].Major);
    for (int CSP= 1; CSP < count; CSP++)
    {
       if (strcmp(GetPersons[CSP].Major,"Computer Science") == 0)
       {
        //printf("%s\n%d\n",GetPersons[CSP].Major,CSP);
        CScount[CSget] = CSP;
        CSget++;
       }
    }

    for (int f=0;f <CSget; f++)
    {
        //printf("%d\n",CScount[f]);
    }

    double GPASum=0;
    double AvgGPA;
    for (int CsGPA= 0; CsGPA < CSget; CsGPA++)
    {
        GPASum = GPASum + GetPersons[CScount[CsGPA]].GPA;
        //printf("%f\n",GPASum);
    }

     AvgGPA = (float)GPASum/CSget;
    printf("%f\n\n",AvgGPA);



    printf("Departments along with the total number of advisors\n");
    char DifMajor[20][100];
    int Majorflags = 0, DifMajorNum = 1;
    int p;
    strcpy(DifMajor[0], GetPersons[1].Major);
    //printf("%s",DifMajor[0]);
    for (int MajorNum = 1; MajorNum < count; MajorNum++)
    {
        Majorflags = 0;
        for (p=0; p<20; p++)
        {
            if (strcmp(GetPersons[MajorNum].Major,DifMajor[p]) != 0)
            {
                //printf("The Dif ----\n");
                Majorflags = 1;
            }
            else if (strcmp(GetPersons[MajorNum].Major,DifMajor[p]) == 0)
            {
                //printf("The same ----\n");
                Majorflags = 0;
                break;
            }
        }
        if (Majorflags)
            {
                strcpy(DifMajor[DifMajorNum],GetPersons[MajorNum].Major);
                strcpy(DifMajor[DifMajorNum+1],"\0");
                DifMajorNum++;
            }
    }

    

    char AdvisorPerMaj[20][50];
    int AdvisorCount, AdvisorFlag = 0, InputFirst = 1;


    for(int MajCount = 0; MajCount < DifMajorNum; MajCount++)
    {
        InputFirst = 1;
        AdvisorCount = 1;
        for (int u=0; u<20 ;u++)
        {
            strcpy(AdvisorPerMaj[u],"\0");
        }
        for (int OrgMajCount= 0; OrgMajCount < count; OrgMajCount++)
        {

            if (strcmp(DifMajor[MajCount],GetPersons[OrgMajCount].Major) == 0)
            {
                //printf("---------Major : %s---------\nFirst Advidor = %sOrgMajCount = %d\n",GetPersons[OrgMajCount].Major,GetPersons[OrgMajCount].Advisor,OrgMajCount);
                if (InputFirst)
                {
                    strcpy(AdvisorPerMaj[0],GetPersons[OrgMajCount].Advisor);
                    //printf("First Advisor = %s",AdvisorPerMaj[0]);
                    InputFirst = 0;
                }

                for (int r = 0; r < 20; r++)
                {
                    if (strcmp(GetPersons[OrgMajCount].Advisor,AdvisorPerMaj[r]) != 0)
                    {
                        AdvisorFlag = 1;
                        //printf("AdvisorFlag = %d\n",AdvisorFlag);
                    }
                    else
                    {
                        //printf("AdvisorFlag = %d\n",AdvisorFlag);
                        AdvisorFlag = 0;
                        break;
                    }

                }
            }

             if (AdvisorFlag)
            {
            strcpy(AdvisorPerMaj[AdvisorCount],GetPersons[OrgMajCount].Advisor);
            AdvisorFlag = 0;
            //printf("AdvisorCount = %d \nGetPersons = %sAdvisorPerMaj = %s\n\n",AdvisorCount,GetPersons[OrgMajCount].Advisor,AdvisorPerMaj[AdvisorCount]);

            AdvisorCount++;
            //printf("AdvisorCount = %d\n",AdvisorCount);
            }
        }
        //for(int l=0;l<20;l++)
        //{
        //      printf("NUM : %d-----NAME: %s\n",l,AdvisorPerMaj[l]);
        //}
        printf("%s : %d\n",DifMajor[MajCount],AdvisorCount);
    }

    //printf("------DONE WITH IT------\n");

    return 0;
}

