#include <stdio.h>

void Menu();
void addAssess();
void viewAll();
void updateAssess();
void dropStudent();
void sortedView();

float grades[5][5];
float originalGrades[5][5];
float studentGrade[5] = {0,0,0,0,0};
float FA, SA;
int student;
int i,j,k,x;

int main (void)
{
	Menu();
	
}

void Menu()
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
				for( i = 0; i < 5; i++)
				{
					if( i <= 2)
					{
						printf("FA %d: ", i + 1);
						scanf("%f", & grades[student-1][i]);
						FA += grades[student-1][i];
					}
					else
					{
						printf("SA %d: ", i - 2);
						scanf("%f", & grades[student-1][i]);
						SA += grades[student-1][i];
					}
				}
				studentGrade [student - 1] = ((FA/3) * .7) + ((SA/2) * .3);
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
                    FA += grades[student-1][i];
                }
                for(i = 3; i < 5; i++)
                {
                    SA += grades[student-1][i];
                }
                studentGrade[student-1] = ((FA/3) * .7) + ((SA/2) * .3);

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

//void dropStudent() {
//    while (1) 
//	{
//        printf("Student <1-5>:");
//        scanf("%d", & student);
//        
//        if (student >= 1 && student <= 5) 
//		{
//            studentGrade[student - 1] = -1; // mark student as dropped
//            printf("Student %d dropped.\n", student);
//            break;
//        } 
//		else 
//		{
//            printf("INPUT INCORRECT!");
//        }
//    }
//}
//
//void viewAll() {
//    printf("\n\tFA1\tFA2\tFA3\tSA1\tSA2\tAVERAGE\tREMARKS\n");
//    for (i = 0; i < 5; i++) 
//	{
//        printf("Student %d:", i + 1);
//        for (x = 0; x < 5; x++) 
//		{
//            printf("%.1f\t", grades[i][x]);
//        }
//        
//        if (studentGrade[i] < 0) // student has been dropped
//		{ 
//			printf("%.1f\t", studentGrade[i]);
//            printf("DROPPED\n");
//        }
//		 
//		else 
//		{
//            printf("%.1f\t", studentGrade[i]);
//            if (studentGrade[i] >= 50) 
//			{
//                printf("PASSED\n");
//            } 
//			else 
//			{
//                printf("FAILED\n");
//            }
//        }
//        printf("\n");
//    }
//}




void dropStudent() {
    while (1) {
        printf("Student <1-5>:");
        scanf("%d", &student);

        if (student >= 1 && student <= 5) {
            originalGrades[student - 1][0] = grades[student - 1][0];
            originalGrades[student - 1][1] = grades[student - 1][1];
            originalGrades[student - 1][2] = grades[student - 1][2];
            originalGrades[student - 1][3] = grades[student - 1][3];
            originalGrades[student - 1][4] = grades[student - 1][4];

            studentGrade[student - 1] = -1; // mark student as dropped
            printf("Student %d dropped.\n", student);
            break;
        } else {
            printf("INPUT INCORRECT!");
        }
    }
}

void viewAll() {
    printf("\n\tFA1\tFA2\tFA3\tSA1\tSA2\tAVERAGE\tREMARKS\n");
    for (i = 0; i < 5; i++) {
        printf("Student %d:", i + 1);
        for (x = 0; x < 5; x++) {
            printf("%.1f\t", grades[i][x]);
        }

        if (studentGrade[i] < 0) { // student has been dropped
            printf("%.1f\t", originalGrades[i][0]);
            printf("%.1f\t", originalGrades[i][1]);
            printf("%.1f\t", originalGrades[i][2]);
            printf("%.1f\t", originalGrades[i][3]);
            printf("%.1f\t", originalGrades[i][4]);
            printf("%.1f\t", studentGrade[i]);
            printf("DROPPED\n");
        } else {
            printf("%.1f\t", studentGrade[i]);
            if (studentGrade[i] >= 50) {
                printf("PASSED\n");
            } else {
                printf("FAILED\n");
            }
        }
        printf("\n");
    }
}


void sortedView()
{
    //int droppedCount = 0;
    float temp;
    int tempIndex;
    
    // Sort studentGrade array in ascending order
    for ( i = 0; i < 4; i++)
    {
        for ( j = i+1; j < 5; j++)
        {
            if (studentGrade[j] >= 0 && (studentGrade[i] < 0 || studentGrade[j] < studentGrade[i]))
            {
                temp = studentGrade[i];
                studentGrade[i] = studentGrade[j];
                studentGrade[j] = temp;
                
                // Swap grades of the corresponding students
                for ( k = 0; k < 5; k++)
                {
                    temp = grades[i][k];
                    grades[i][k] = grades[j][k];
                    grades[j][k] = temp;
                }
            }
        }
    }
    
    // Move students with dropped grades to the end of the array
    for ( i = 0; i < 4; i++)
    {
        if (studentGrade[i] < 0)
        {
            for ( j = i+1; j < 5; j++)
            {
                if (studentGrade[j] >= 0)
                {
                    temp = studentGrade[i];
                    studentGrade[i] = studentGrade[j];
                    studentGrade[j] = temp;

                    // Swap grades of the corresponding students
                    for ( k = 0; k < 5; k++)
                    {
                        temp = grades[i][k];
                        grades[i][k] = grades[j][k];
                        grades[j][k] = temp;
                    }

                    break;
                }
            }
        }
    }
    
//    // Count number of dropped students
//    for ( i = 0; i < 5; i++)
//    {
//        if (studentGrade[i] < 0)
//        {
//            droppedCount++;
//        }
//    }
    
    // Print sorted view
    printf("\n\tFA1\tFA2\tFA3\tSA1\tSA2\tAVERAGE\tREMARKS\n");
    for ( i = 0; i < 5 ; i++)
    {
        printf("Student %d:", i + 1);
        for ( j = 0; j < 5; j++)
        {
            printf("%.1f\t", grades[i][j]);
        }
        printf("%.1f\t", studentGrade[i]);
        if (studentGrade[i] >= 50)
        {
            printf("PASSED\n");
        }
        if (studentGrade[i] < 50)
        {
            printf("FAILED\n");
        }
        	printf("%.1f\t", studentGrade[i]);
        	printf("DROPPED\n");
    }
//    for ( i = 0; i < droppedCount; i++)
//    {
//        
//    }
}








