#include <stdio.h>

void menu();
void addAssess();
void viewAll();
void updateAssess();
void dropStudent();
void sortedView();
void sort();

float grades[5][5];
float originalGrades[5][5];
float studentGrade[5] = {0,0,0,0,0};
int viewOrder[5] = {0, 1, 2, 3, 4};

/*
 * 0 = Dropped
 * 1 = Failed
 * 2 = Passed
 */
int remark[5] = {1, 1, 1, 1, 1};
float FA, SA;
int student;
int i, j, x;

int main (void)
{
	menu();
}

void menu()
{
	int choice;
	
	while (1)
	{
	printf("1.) Input Assessment \n2.) Update Assessment \n3.) Drop Students \n4.) View All \n5.) Sorted View \n6.) Exit \nChoice:");
	scanf("%d",&choice);
	
		switch(choice)
		{
			case 1:
				addAssess();
				break;
			case 2:
			    updateAssess();
				break;
			case 3:
			    dropStudent();
			    break;
			case 4:
			    viewAll();
				break;
			case 5:
			    sortedView();
			    break;
			case 6:
			    exit(0);
			default:
				printf("WRONG INPUT!");
				break;
		}	
	}
}

// Done
void addAssess()
{
	while(1)
	{
		printf("Student <1-5>:");
		scanf("%d", & student);
		
		if( student >= 1 && student <= 5)
		{
			FA = 0;
			SA = 0;
			int studentNo = student - 1;
			for( i = 0; i < 5; i++)
			{
				if( i <= 2)
				{
					printf("FA %d: ", i + 1);
					scanf("%f", & grades[student-1][i]);
					FA += grades[studentNo][i];
				}
				else
				{
					printf("SA %d: ", i - 2);
					scanf("%f", & grades[student-1][i]);
					SA += grades[studentNo][i];
				}
			}
			float studentAvg = ((FA/3) * .7) + ((SA/2) * .3);
			studentGrade[studentNo] = studentAvg;
			
			if (studentAvg >= 50)
			{
				remark[studentNo] = 2; // Student passed
			}
			break;
		}
		else
		{
			printf("INPUT INCORRECT!");
		}
	}							
}

void updateAssess()
{
    int assess;
    float FA = 0, SA = 0;
	
    while(1)
    {
        printf("Student <1-5>: ");
        scanf("%d", &student);
		int studentNo = student - 1;
        if(student >= 1 && student <= 5)
        {
            printf("<1> FA 1\n<2> FA 2\n<3> FA 3\n<4> SA 1\n<5> SA 2\nChoose Assessment <1-5>: ");
            scanf("%d", &assess);

            if(assess >= 1 && assess <= 5)
            {
                if(assess <= 3)
                {
                    printf("FA %d [current grade = %.1f]: ", assess, grades[student-1][assess-1]);
                    scanf("%f", &grades[student-1][assess-1]);
                }
                else
                {
                    printf("SA %d [current grade = %.1f]: ", assess-3, grades[student-1][assess-1]);
                    scanf("%f", &grades[student-1][assess-1]);
                }

                // Calculate the new student grade
                for(i = 0; i < 3; i++)
                {
                    FA += grades[studentNo][i];
                }
                for(i = 3; i < 5; i++)
                {
                    SA += grades[studentNo][i];
                }
                
                float studentAvg = ((FA/3) * .7) + ((SA/2) * .3);
				studentGrade[studentNo] = studentAvg;
				
				if (studentAvg >= 50)
				{
					remark[studentNo] = 2; // Student passed
				}
				
                printf("Student %d updated.\n", student);
                break;
            }
            else
            {
                printf("Invalid assessment choice!\n");
            }
        }
        else
        {
            printf("Invalid student choice!\n");
        }
    }
}

void dropStudent() {
	int studentNo;
    while (1) 
	{
        printf("Student <1-5>:");
        scanf("%d", & student);
        studentNo = student - 1;
        
        if (student >= 1 && student <= 5) 
		{
            remark[studentNo] = 0; // mark student as dropped
            printf("Student %d dropped.\n", student);
            break;
        } 
		else 
		{
            printf("INPUT INCORRECT!");
        }
    }
}

void viewAll() {
    printf("\n\t\tFA1\tFA2\tFA3\tSA1\tSA2\tAVERAGE\tREMARKS\n");
    for (i = 0; i < 5; i++) 
	{
        printf("Student %d:\t", i + 1);
        for (x = 0; x < 5; x++) 
		{
            printf("%.1f\t", grades[i][x]);
        }
        
        printf("%.1f\t", studentGrade[i]);
        if (remark[i] == 0)
        {
        	printf("DROPPED\n");
		}
		else if (remark[i] == 1)
		{
			printf("FAILED\n");
		}
		else if (remark[i] == 2)
		{
			printf("PASSED\n");
		}
		else
		{
			printf("N/A");
		}
    }
}


void sortedView()
{
	sort();
	for (i = 0; i < 5; i++) 
	{
		int currentView = viewOrder[i];
        printf("Student %d:", currentView + 1);
        for (x = 0; x < 5; x++) 
		{
            printf("%.1f\t", grades[currentView][x]);
        }
        
        printf("%.1f\t", studentGrade[currentView]);
        if (remark[currentView] == 0)
        {
        	printf("DROPPED\n");
		}
		else if (remark[currentView] == 1)
		{
			printf("FAILED\n");
		}
		else if (remark[currentView] == 2)
		{
			printf("PASSED\n");
		}
		else
		{
			printf("N/A");
		}
    }
}

void sort()
{
	int min;
	int n = 5;
	for (i = 0; i < n-1; i++)
	{
		min = i;
		for (j = i+1; j < n; j++)
		{
			if ((studentGrade[min] > studentGrade[j]) && (remark[min] != 0 && remark[j] != 0))
			{
				min = j;	
			}
			if (remark[min] == 0 && remark[j] != 0)
			{
				min = j;
			}
		}
		
		if (min != i)
		{
			swap(&studentGrade[i], &studentGrade[min]);
			
			swap(&remark[i], &remark[min]);
			for (j = 0; j < 5; j++)
			{
				swap(&grades[i][j], &grades[min][j]);
			}
		}
	}
}

void swap(int *xp, int *yp)
{
	int tmp = *xp;
	*xp = *yp;
	*yp = tmp;
}





