#include <stdio.h>
#include <string.h>

#define QUESTIONS 5
#define ANSWERS 5
#define LIMIT 500

char ** getStudentAnswers(const char ** questions, int n, int len);
int ** ans2Vectors(char *instructor_answer, char *student_answer);
double cosineSimilarity(char *instructor_answer, char *student_answer);
int computeUniqueWords(char string[]);

int main(void){
	const char * questions[QUESTIONS] = {"What are local variables?", "What is an identifier?", "What is recursion?", "What is a pointer?", "What is the purpose of applying static to a local array?"};
	
	char * instructor_answers[ANSWERS] = {"Variables defined in function definition are local variables. They can be accessed only in the function scope.", "Identifiers are user defined names given to variables, functions, and arrays.", "A function calling itself again and again to compute a value is referred to as a recursive function or recursion. Recursion is useful for branching processes and is effective where terms are generated successively to compute a value.", "A pointer is a variable that stores the memory address of another variable as its value.", "By making a local array definition static the array is not created an initialized every time the function is called and it is not destroyed every time the function is exited. Also, the execution time is reduced."};

	char ** student_answers = getStudentAnswers(questions, QUESTIONS, LIMIT);

	double similarities[QUESTIONS];

	for(int i = 0; i < ANSWERS; i++){
		similarities[i] = cosineSimilarity(instructor_answers[i], student_answers[i]); //char* inst_ans, char* stud_ans
	}

	double sum = 0;
	for(int i = 0; i < QUESTIONS; i++){
		sum += similarities[i];
		printf("Your score for question %d is %f out of 10.\n", i+1, similarities[i]);
	}

	double average = sum / QUESTIONS;
	printf("Average score for all questions is %f out of %d.\n", average, QUESTIONS);
}

//return array of pointers to arrays
char ** getStudentAnswers(const char ** questions, int n, int len){
	char* studAnswers[ANSWERS] = {};
	char** iPtr = &studAnswers[0];
	for(int i = 0; i < n; i++){
		printf("%s\n", questions[i]);
		scanf(" %s", *iPtr);
		iPtr++;
	}
	return studAnswers;
}

int ** ans2Vectors(char *instructor_answer, char *student_answer){

	for(int i = 0; instructor_answer[i] != '\0'; i++){
		if(instructor_answer[i] >= 65 && instructor_answer[i] <= 90){ //is an uppercase letter
			instructor_answer[i] += 32; //lowercase counterpart is 32 away 
		}
	}

	for(int i = 0; student_answer[i] != '\0'; i++){ //repeat for student answer
                if(student_answer[i] >= 65 && student_answer[i] <= 90){ //is an uppercase letter
                        student_answer[i] += 32; //lowercase counterpart is 32 away
                }
        }
}

double cosineSimilarity(char *instructor_answer, char *student_answer){
	//call ans2Vectors() on parameters
	int ** inst_vector = ans2Vectors(instructor_answer);
	int ** stud_vector = ans2Vectors(student_answer);
}

int computeUniqueWords(char string[LIMIT]){
	int numSpaces = 0;
	for(int i = 0; string[i] != '\0'; i++){
		if(string[i] == ' '){
			numSpaces++;
		}
	}
	
	int b[15][20];

	for(int i = 0; i < numSpaces+1; i++){
		
		int j = 0;
		for(int k = 0; string[k] != '\0'; k++){
			if(string[k] != ' '){
				break;
			} else{
				b[i][j++] = string[i];		
			}
		}
		b[i][j] = '\0';
	}
}
