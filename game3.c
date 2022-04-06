#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <pthread.h>
#include <unistd.h>
#include <string.h>
#include <ctype.h>
typedef struct studen
{
	int x[100], y[100];
	char a[30][30];
	int n;
	int f;
	int m;
	int food;
} stp;
void m0p(stp *s)
{
	int i, j, k;
	for (i = 0; i < 50; i++)
	{
		for (j = 0; j < 50; j++)
			s->a[i][j] = '.';
	}
	s->n = 1;
	s->f = 4;
	s->x[0] = 1, s->y[0] = 1;
	/*	s->x[1] = 0, s->y[1] = 1;
	s->x[2] = 0, s->y[2] = 0;
	s->x[3] = 1, s->y[3] = 0;
	s->x[4] = 2, s->y[4] = 0;
	for (i = 0; i < s->n; i++)
	*/
	s->a[s->x[0]][s->y[0]] = 'O';
	s->m = 1;
	s->food = 0;
//	s->point = 0;
}
void put(stp *s)
{
	int i, j, k;
	while(1)
	{
		k = 0;
		for (i = 0; i < 30; i++)
		{
			for (j = 0; j < 30; j++)
			{
				if (s->a[i][j] == '$')
				{
					s->food = 1;
					k = 1;
					break;
				}
			}
			if (s->a[i][j] == '$')
				break;
		}
		if (k == 0)
			s->food = 0;
		printf("your point is:%d\n", s->n-1);

		for (i = 0; i < 30; i++)
		{
			for (j = 0; j < 30; j++)
				printf("%c ", s->a[i][j]);
			printf("\n");
		}
		usleep(200000);
		system("cls");
	}
}
void upp(stp *s)
{
	int i, j, k;
	int now = 0;
	if (s->a[s->x[0] - 1][s->y[0]] == '$')
	//	s->point++;
		/*	if(s->x[s->n-1]-s->x[s->n-2]==-1)
		s->x[s->n]=s->x[s->n-1]-1;
		s->y[s->n]=s->y[s->n-1];
		s->a[s->x[s->n]][s->y[s->n]]='O';
		*/
		s->n = s->n + 1;
	if (s->a[s->x[0] - 1][s->y[0]] == 'O')
		s->m = 0;
	if (s->x[0] != 0)
	{
		s->a[s->x[now] - 1][s->y[now]] = s->a[s->x[now]][s->y[now]];
		s->a[s->x[now]][s->y[now]] = '.';
		s->x[now] = s->x[now] - 1;
	}
	else
	{
		s->a[s->x[0]][s->y[0]] = '.';
		s->x[0] = 29;
		s->a[s->x[0]][s->y[0]] = 'O';
	}
}
void donn(stp *s)
{
	int now = 0;
	if (s->a[s->x[0] + 1][s->y[0]] == '$')
	//	s->point++;
		s->n = s->n + 1;
	if (s->a[s->x[0] + 1][s->y[0]] == 'O')
		s->m = 0;
	if (s->x[0] != 29)
	{
		s->a[s->x[now] + 1][s->y[now]] = s->a[s->x[now]][s->y[now]];
		s->a[s->x[now]][s->y[now]] = '.';
		s->x[now] = s->x[now] + 1;
	}
	else
	{
		s->a[s->x[0]][s->y[0]]='.';
		s->x[0]=0;
		s->a[s->x[0]][s->y[0]]='O';
	}
}
void leff(stp *s)
{
	int now = 0;
	if (s->a[s->x[0]][s->y[0] - 1] == '$')
	//	s->point++;
		s->n = s->n + 1;
	if (s->a[s->x[0]][s->y[0] - 1] == 'O')
		s->m == 0;
	if (s->y[0]!=0)
	{
		s->a[s->x[now]][s->y[now] - 1] = s->a[s->x[now]][s->y[now]];
	s->a[s->x[now]][s->y[now]] = '.';
	s->y[now] = s->y[now] - 1;
	}
	else
	{
		s->a[s->x[0]][s->y[0]]='.';
		s->y[0]=29;
		s->a[s->x[0]][s->y[0]]='O';
	}
}
void righh(stp *s)
{
	int now = 0;
	if (s->a[s->x[0]][s->y[0] + 1] == '$')
	//	s->point++;
		s->n = s->n + 1;
	if (s->a[s->x[0]][s->y[0] + 1] == 'O')
		s->m = 0;
	if (s->y[0]!=29)
	{
		s->a[s->x[now]][s->y[now] + 1] = s->a[s->x[now]][s->y[now]];
	s->a[s->x[now]][s->y[now]] = '.';
	s->y[now] = s->y[now] + 1;
	}
	else
	{
		s->a[s->x[0]][s->y[0]]='.';
		s->y[0]=0;
		s->a[s->x[0]][s->y[0]]='O';
	}
}
void skp(stp *s)
{
	int i, j, k, z, b, c;
	while(1)
	{
		k = s->x[0], z = s->y[0];
		switch (s->f)
		{
		case 1:
			upp(s);
			break;
		case 2:
			donn(s);
			break;
		case 3:
			leff(s);
			break;
		case 4:
			righh(s);
			break;
		}
		for (i = 1; i < s->n; i++)
		{
			s->a[s->x[i]][s->y[i]] = '.';
			b = s->x[i], c = s->y[i];
			s->x[i] = k, s->y[i] = z;
			k = b, z = c;
			s->a[s->x[i]][s->y[i]] = 'O';
		}
		usleep(200000);
	}
}
void eat(stp *s)
{
	int i, j, k[2];
	while(1)
	{
		usleep(10000);
		if (s->food == 0)
		{
			for (;;)
			{
				srand((unsigned)time(NULL));
				k[0] = rand() % 20;
				k[1] = rand() % 19;
				if (s->a[k[0]][k[1]] != 'O')
					break;
			}
			s->a[k[0]][k[1]] = '$';
			s->food = 1;
		}
	}
}
void snake()
{
	stp s;
	m0p(&s);
	pthread_t th1;
	pthread_t th2;
	pthread_t th3;
	pthread_create(&th1, NULL, put, &s);
	pthread_create(&th2, NULL, skp, &s);
	pthread_create(&th3, NULL, eat, &s);
	while(1)
	{
		if (s.m == 0)
		{
			printf("you lost !");
			break;
		}
		switch (getch())
		{
		case 'w':
			s.f = 1;
			break;
		case 's':
			s.f = 2;
			break;
		case 'a':
			s.f = 3;
			break;
		case 'd':
			s.f = 4;
			break;
		}
	}
}