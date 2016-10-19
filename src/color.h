#define FRONT_START 30
#define FRONT_END 37
#define BACK_START 40
#define BACK_END 47

#define NO 0
#define YES 1
/* Define the struct of colorcode.  */
typedef struct {
	int front;
	int back;
	int property;
} colorcode;

/* Print the all color table.  */
int printtable(void);

/* Function to get color by the number code.  */
int getcolor(const char *arg);
