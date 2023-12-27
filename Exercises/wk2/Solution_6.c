#include <stdio.h>

void filterStudents(int students[][4], int minAge, int minYear, int minGrade); 

int main(void){
	//int studentData[4][4] = {{1, 15, 9, 85}, {2, 17, 11, 74}, {3, 16, 10, 97}, {4, 18, 12, 70}};
	int studentData[3][4] = {{1, 18, 12, 90}, {2, 16,10,75}, {3, 15, 9, 85}}; 

	int minAge, minYear, minGrade;

	printf("---Student Directory---\n");
	printf("Please fill out the following filter material. Enter -1 if you do not want a criterion to be considered.\n");

	printf("Please enter desired minimum age:\n");
	scanf("%d", &minAge);

	printf("Please enter desired minimum year:\n");
	scanf("%d", &minYear);

	printf("Please enter desired minimum grade:\n");
	scanf("%d", &minGrade);

	filterStudents(studentData, minAge, minYear, minGrade);

}

void filterStudents(int students[][4], int minAge, int minYear, int minGrade){
	int selected[3]; //array that will be used to store the ids of students that fit the user-entered filters

	int ageMet, yearMet, gradeMet;

	int counter = 0;
	for(int i = 0; i < 3; i++){
		if(minAge != -1){
			if(students[i][1] >= minAge){
				ageMet = 1;
			} else{
				ageMet = 0;
			}
		} else{
			ageMet = 1; //automatically counting it as passed if user entered -1
		}

		if(minYear != -1){
                        if(students[i][2] >= minYear){
                                yearMet = 1;
                        } else{
                                yearMet = 0;
                        }
                } else{
                        yearMet = 1; //automatically counting it as passed if user entered -1
                }
		if(minGrade != -1){
                        if(students[i][3] >= minGrade){
                                gradeMet = 1;
                        } else{
                                gradeMet = 0;
                        }
                } else{
                        gradeMet = 1; //automatically counting it as passed if user entered -1
                }
		
		if(ageMet == 1 && yearMet == 1 && gradeMet == 1){
			selected[counter] = students[i][0]; //add student id to final array if all three are met
			counter++;
		}
	}
	
	if(counter != 0){
		for(int i = 0; i < counter; i++){
			printf("%d ", selected[i]);
		}
		printf("\n");
	} else{
		printf("No students found.\n");
	}
}
