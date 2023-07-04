#include<stdio.h> 
int main() {   
	int i=0; 
	int h[9]={0}, x[3]={0}, y[3]={0};     
	FILE *input = fopen("../input/4.txt","r"); 
	for(i = 0; i<9; i++) fscanf(input, "%d", &h[i]); 
	for(i = 0; i<3; i++) fscanf(input, "%d", &x[i]); 
	for(i = 0; i<3; i++) fscanf(input, "%d", &y[i]);   
	fclose(input); 
	int *p_x = &x[0] ; int *p_h = &h[0] ; int *p_y = &y[0] ; 
	asm volatile(
		"mul %[H0],%[H0],%[X0]\n\t"
		"add %[Y0],%[Y0],%[H0]\n\t"
		"mul %[H1],%[H1],%[X1]\n\t"
		"add %[Y0],%[Y0],%[H1]\n\t"
		"mul %[H2],%[H2],%[X2]\n\t"
		"add %[Y0],%[Y0],%[H2]\n\t"
		"mul %[H3],%[H3],%[X0]\n\t"
		"add %[Y1],%[Y1],%[H3]\n\t"
		"mul %[H4],%[H4],%[X1]\n\t"
		"add %[Y1],%[Y1],%[H4]\n\t"
		"mul %[H5],%[H5],%[X2]\n\t"
		"add %[Y1],%[Y1],%[H5]\n\t"
		"mul %[H6],%[H6],%[X0]\n\t"
		"add %[Y2],%[Y2],%[H6]\n\t"
		"mul %[H7],%[H7],%[X1]\n\t"
		"add %[Y2],%[Y2],%[H7]\n\t"
		"mul %[H8],%[H8],%[X2]\n\t"
		"add %[Y2],%[Y2],%[H8]\n\t"
		:[Y0] "+r"(*p_y),[Y1] "+r"(*(p_y+1)),[Y2] "+r"(*(p_y+2))
		:[X0] "r"(*p_x),[X1] "r"(*(p_x+1)),[X2] "r"(*(p_x+2)),[H0] "r"(*p_h),[H1] "r"(*(p_h+1)),[H2] "r"(*(p_h+2)),[H3] "r"(*(p_h+3)),[H4] "r"(*(p_h+4)),[H5] "r"(*(p_h+5)),[H6] "r"(*(p_h+6)),[H7] "r"(*(p_h+7)),[H8] "r"(*(p_h+8))
	);   
	p_y = &y[0]; 
	for(i = 0; i<3; i++) 
	printf("%d \n", *p_y++); 
	return(0) ;  
}
