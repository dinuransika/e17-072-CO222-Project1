/******************************************************************************/
// Dinura Ransika Dissanayake 
// E17072
// Project 1 - CO222 - Programming Methodology
/*----------------------------------------------------------------------------*/


#include<stdio.h>
#include<string.h>


#define small  24
#define large  132
#define BLACK 		0
#define	WHITE		7
#define gotoxy(x,y) printf("\033[%d;%dH", (y), (x+1))
#define Clear() printf("\033[H\033[J")


char* colors[]={"black", "red", "green", "yellow", "blue", "magenta", "cyan", "white"};


void  dispArray(int SIZE, int array[SIZE]); //Prototypes
void reverse(int SIZE, int arr[SIZE]);
void adder(int arr1[], int arr2[], int init, int SIZE);
int * Binary(int n);
void Box(int color);
void move_right(int x);
void move_up(int y);
void Position(int x, int y, int color);
void unit(int n[9], int x, int y, int color);
void Frame(int n, int color);
int indexof(char * str, char ** strarray);
int isinarr(char * str, char ** strarray);
void Tolower(char arr[]);
void help(char * progname);

int main(int argc, char *argv[]){
    static int col=0;
    char progname[100];
    strcpy(progname, argv[0]);
    if(argc==1) col = BLACK;  //Argument handelling.
    else{
		if(strcmp(argv[1], "-c")==0){
			if(argc==3){
				char inpcolor[strlen(argv[2])];
				strcpy(inpcolor, argv[2]);
				Tolower(inpcolor);
				if(isinarr(inpcolor, colors)==0) col = indexof(inpcolor, colors);
				else {printf("Invalid argument for color.\n"); help(progname); return 0;}
			}else{
				if(argc>3) {printf("Incorrect usage of arguments.\n"); help(progname); return 0;} //Too many arguments.		
			      	else {printf("Incorrect usage of arguments.\n") ; help(progname); return 0;} 
			     }
		}else{
		 		if(strcmp(argv[1], "-h")==0){ help(progname);	return 0;} //Help	
				else {help(progname); return 0;}
				}	
	}
	
	

    char str[1000];
    static int i, length, hstr_s[small], count=0, hstr_l[large], j;
    printf("Enter url :- ");
    scanf("%s", str);
    length = strlen(str);
    int tempstr_s[small - 1 - length];



    if(length<=3 || length>120){
        if(length<=3) {printf("String is too short. Not supported by available QR versions\n"); return 0;} //Checking the length.
        else {printf("String is too long. Not supported by available QR versions\n"); return 0;}
	}
    else if(length>3 && length<=20){
	Clear(); //Clear the screen.
        //first_char = small + length;
        hstr_s[0] = 50 + length;
        for(i=1 ; i<=length ; i++){//Appending the input str.
        hstr_s[i] = str[i-1];
    }
    
    for(i= 0 ; i<(small - 1 - length) ; i++){//Error Correction part.
        tempstr_s[i] = str[i%length] + ((count/length) + 1);
        count++;
    }
        reverse(small - 1 - length, tempstr_s);
        adder(hstr_s, tempstr_s, length+1, small);
	Frame(38, col);
	int x;
	for(x=0 ; x<16 ; x++){                                              
		unit(Binary(hstr_s[x]), 8+6*((x%4)+1), 8+3*(x/4), col);
		}
	j=0;                                                                     //Printing the QR code.
	for(x=x ; x<20 ; x++){ 
		unit(Binary(hstr_s[x]), 8+6*((x%2)+1), 2+3*(j/2), col);
		j++;
		}
	j=0;
	for(x=x ; x<24 ; x++){  
		unit(Binary(hstr_s[x]), 2+6*((j%2)), 8+3*(j/2), col);
		j++;
		}
	gotoxy(0, 22);

       

    }else{if(length>20 && length<=120){
	Clear();
        //first_char = large + length;
        gotoxy(0,0);
        hstr_l[0] = 50 + length;
        for(i=1 ; i<=length ; i++){
        hstr_l[i] = str[i-1];
    }
    
    int f = length + 1;
	for(int cou=1;f<large;cou++){
		for(int k=0;k<length;k++){
			if(f<large){
			hstr_l[f++] = str[k]+cou;
			}
		}
	}
	int low = length+1, high = (length-1);
	while(low<high){
		int p=hstr_l[low];
		hstr_l[low] = hstr_l[high];
		hstr_l[low] = p;
		low++;
		high--;
	}
	Frame(74, col);
	for(i=0 ; i<100 ; i++){  //Big Square
		unit(Binary(hstr_l[i]), 8+6*((i%10)+1), 8+3*(i/10), col);
		}
	j=0;
	for(i=100 ; i<116 ; i++){                                                        //Printing the QR code.
		unit(Binary(hstr_l[i]), 8+6*(((i-100)%8)+1), 2+3*(j/8), col);
		j++;
		}
	j=0;
	for(i=116 ; i<132 ; i++){  
		unit(Binary(hstr_l[i]), 2+6*((j%2)), 8+3*(j/2), col);
		j++;
		}
	gotoxy(0, 41);
		    }
    }
    return 0;
}



void  dispArray(int SIZE, int array[SIZE]){// For testing purposes.
    int j;
    for(j=0 ; j<SIZE ; j++){
        printf("%d\n", array[j]);
    }
}
void reverse(int SIZE, int arr[SIZE])
{
	for (int low = 0, high = SIZE - 1; low < high; low++, high--)
	{
		int temp = arr[low];
		arr[low] = arr[high];
		arr[high] = temp;
	}
}
void adder(int arr1[], int arr2[], int init, int SIZE){
    int i, j=0;
    for(i=init; i<SIZE ; i++){
        arr1[i] = arr2[j];
        j++;
    }
}
int * Binary(int n) { 
    int i = 0; 
    static int binaryNum[9]= {0,0,0,0,0,0,0,0,0};
    while (i < 9) { 
  
        binaryNum[i] = n % 2; 
        n = n / 2; 
        i++; 
    } 
    reverse(9, binaryNum);
    return binaryNum;
} 

void unit(int n[9], int x, int y, int color){
    int i;
    for(i=0 ; i<9 ; i++){
        gotoxy(x + 2*(i%3), y + (i/3));
        if(n[i]==0){
            Box(WHITE);
        }else{
            Box(color);
        }
    }
}
void Box(int color){
	printf("%c[%dm\u2588\u2588%c[0m", 0x1B, color + 30, 0x1B);
}

void move_right(int x){
	printf("\033[%dC", x); // Move right X column;
}

void move_up(int y){
	printf("\033[%dA", y); // Move up X lines;
}
void Position(int x, int y, int color){
	unit(Binary(485), x, y, color);
	unit(Binary(461), x + 6, y, color);
	unit(Binary(359), x , y + 3, color);
	unit(Binary(335), x + 6 , y + 3, color);
}
void Frame(int n, int color){
	int i;
	gotoxy(0, 0);
	for(i=0 ; i<n ; i++){
		Box(7);
		gotoxy(i+1, 0);
		}
	for(i=0 ; i<((n)/2)+1 ; i++){
		gotoxy(0, i+1);
		Box(7);
		gotoxy(n, i+1);
		Box(7); 	
		}
	for(i=0 ; i<n ; i++){
		gotoxy(i, ((n)/2)+1);
		Box(7);
		}
	Position(2, 2, color);
    	Position(n-12, 2, color);
    	Position(2, (n-10)/2, color);
	
}
void Tolower(char arr[]){
	int i;
	for(i=0 ; i<strlen(arr) ; i++){
		if(arr[i] > 'A' && arr[i] < 'Z') arr[i] = arr[i]+32;
	}
}
int indexof(char * str, char ** strarray){
	int i;
	for(i=0 ; i<8 ; i++) if(strcmp(str, strarray[i])==0) return i;
	return -1;
}
int isinarr(char * str, char ** strarray){
	if(indexof(str, strarray)!=-1) return 0;
	else return -1;
}
void help(char * progname){
	printf("usage :\n");
	printf("%s -c [black|red|green|yellow|blue|magenta|cyan]\n",progname);
	printf("%s -h for help about the program\n",progname);
}