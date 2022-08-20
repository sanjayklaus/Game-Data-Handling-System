// BT20CSE113 LIKHITH SANJAY SOLLETI DSPD ASSIGNMENT 1.
#include <stdio.h>
#include<stdlib.h>
#include<string.h>
#include <conio.h>
#define size 1000

typedef struct player_information
{
	char playerID[30];
	char name[50]; 
	char reg_date[30];
	char gameID[30];
	int no_of_players
	int  game_played;
	int games_won;
	int scores;
	int prizes;
	char game_preferences[50];
}player_information;

typedef struct game_master
{
    char gameID[30];
    char name[50];
    char type[30];
    int no_of_players;
}game_master;

typedef struct games_played
{
    char gameID[30]; 
    char playerID[30];
	int score,awards,active_days;
	char starting_date[30];
	char ending_date[30];
}games_played;

typedef struct guest_user
{
        char id[30];
        char name[50]; 
        char date[30];
}guest_user;

void initialise_player(struct player_information info[size])
{
	int i;
	for (i=0;i<size;i++)
	{
		info[i].playerID[0] ='\0';
		info[i].name[0] ='\0';
		info[i].gameID[0] ='\0';
		info[i].reg_date[0] ='\0';
		info[i].games_played = 0;
		info[i].games_won = 0;
		info[i].prizes = 0;
		info[i].no_of_players = 0;
		info[i].game_preferences[0] ='\0';
	}
  
}
void initialise_gameMaster(struct game_master master[size] )
{
	int i,j;
	for (i=0;i<size;i++)
	{
		master[i].gameID[0] ='\0'; 
        master[i].name[0] ='\0';
        master[i].type[0] ='\0';
		master[i].no_of_players = 0;
    }
}
void initialise_gamesPlayed(struct games_played played[size] )
{
    int i;
	for (i=0;i<size;i++)
	{
		played[i].gameID[0] ='\0';
		played[i].playerID[0] ='\0';
		played[i].score = 0;
		played[i].awards = 0;
		played[i].active_days = 0;
		played[i].starting_date[0] ='\0';
		played[i].ending_date[0] ='\0';
	}
}
void initialise_guest_user(struct guest_user guest[size])
{
	int i;
	for (i=0;i<size;i++)
	{
		guest[i].id[0] = '\0';
		guest[i].name[0] = '\0';
		guest[i].date[0] = '\0';
	}
}


 void printfun(struct player_information info[],int i)
  {
  
	printf("Player ID %s \n",info[i].playerID);
	printf(" name %s\n",info[i].name);
	printf(" gameID %s \n",info[i].gameID);
	printf(" game preferences %s \n",info[i].game_preferences);	
}


void add_user(player_information *h,player_information p,int *size)
{
	int n=*size;
	printf("enter player id:");
	scanf("%s",p.playerID);
	int i,found=0;
	for(i=0;i<n&& found==0;i++)
	{
		if(h[i].playerID==p.playerID)
		{
			found=1;
		}
	}
	if(found==1)
	{
		printf("player id already exist.check the id ");
	}
	else
	{
		printf("\n enetr the name:");
 	    scanf("%s",&p.name);
 	    
 	    printf("\n enetr the registration date:");
 	    scanf("%s",&p.reg_date);
 	    
 	    printf("\n enetr the no.of games played:");
 	    scanf("%d",&p.games_played);
 	    
 	    printf("\n enetr the no.of games won:");
 	    scanf("%d",&p.games_won);
 	    
 	    printf("\n enetr the game preferences:");
 	    scanf("%s",&p.game_preferences);
	}
	*size=n;
}

void sort(struct games_played played1[],int space)
{
	int i,j;
	for(i=0;i<space;i++)
	{
		printf("\nEnter the Game ID:");
		scanf("%s",played1[i].gameID);
		
		printf("\nEnter the player ID:");
		scanf("%s",played1[i].playerID);
		
		printf("\nEnter the active days:");
		scanf("%d",played1[i].active_days);
		
	}
	int max = played1[0].awards;
	i = j;
	for(j=0;j<space;j++)
	{
		if(played1[0].awards < played1[j].awards)
		{
			max = played1[j].awards;
			j=i;
		}
    }
	printf("%s",played1[i].gameID);
	printf("%s",played1[i].playerID);
	printf("%d",played1[i].active_days);
    
}

void search_name(struct player_information k[],int M,int r,char name[],char gameID) //2nd search by name
{
 	
 	int i;
 	
 	for(i=0;i<M+r;i++)
 	{
 		
 		if((strcmp(k[i].name,name)==0)&&(strcmp(k[i].gameID,gameID)==0))
 		  {
 		  	printfun(info,i);
 		  	i=M+r+1;
 		  	
		  }
	}
 	
 	if(i==M+r)
 	{
 		printf("\n no records are avalaible");
	}
 	
}
void inactive_user(player_information p[],int players_count,games_played played[],int game_count)
{
    int inactv_user[100];
    int i,j,k,p,days;
    int inactv_count=-1;

    for( i=0;i<game_count;i++)
	{

        for( j=0;j<played[i].ply_count;j++)
		{
            days=(int)(played[i].ending_date[0]-played[i].starting_date[0])*10+(int)(played[i].ending_date[1]-played[i].starting_date[1])+1;
             for( k=0;k<info[i].no_of_players;k++)
			 {
                 if(games_played[i].active_days[k]<days )
				 {
                     //check if usr is alredy noted or not
                     if(inactv_count==-1)
                        inactv_user[++inactv_count]=played[i].playerID[k];
                    else{
                        int flag=1;
                        for( p=0;p<inactv_count&&flag;p++)
						{
                            if(played[i].playerID[k]==inactv_user[p])
                                flag=0;
                        }
                        if(flag==1)
                        inactv_user[++inactv_count]=played[i].playerId[k];
                    }

                 }
             }
        }
         printf("gameID: %d inactive user are :\n",i);
        for(int i=0;i<inactv_count;i++)
		{
            printf(" %s\n",info[inactv_user[i]].name);
        }
    }
  
}
void active_user( player_information info[],int players_count,int k)
{
    
    printf("Active users :-\n");
    for(int i=0;i<players_count;i++)
	{
        if(info[i].name>k)
		{
            printf("ID: P%d\t%s\n",info[i].playerID,info[i].name);
        }
    }

}
void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}
void bubbleSort(int a[][2], int n,int p)
{
    int i, j;
    int q=(n>p+1)?p+1:n;
    for (i = 0; i < q-1; i++)  
	{  
      for (j = 0; j < n-i-1; j++)
       { 
           if (a[j][0] > a[j+1][0])
            swap(&a[j][0], &a[j+1][0]);
       }
    }
}


void top_5(games_played played[],int game_count)
{

       int d[50][2];
       int i,j,days=0;
       for(i=0;i<game_count;i++)
	   {
           for(j=0;j<played[i].player_count;j++)
		   {
               
                  days+=count_days(played[i].starting_date,played[i].ending_date)+1;
           }
           data[i][0]=days;
           data[i][1]=i;
       }
      bubbleSort(d,50,5);
      for(int i=game_count-1;i>game_count-1-5;i--)
        printf("Game_id: %d  days: %d\n",data[i][1],data[i][0]);


}


void d_order(struct game_master master[],char gameID[])
{
    int i=0,found=0,loc=0;
    while(i<size&&!found)
    {
        if(strcmp(master[i].gameID,gameID)==0)
        {
            found=1;
            loc=i;
        }
        i++;
    }
    if(found==1)
    {
        printf("%s %s \n",master[loc].name,master[loc].type);
        printf("Enter the list in descending order\n");
	    scanf("%s",gameID);
    }
    else
    {
        printf("Enterd details are not found in data base\n");
    }

}
int main()
{
	int ch,i,n,k,M,r,name,;
	struct player_information info[size];
	struct game_master master[size];
	struct games_played played[size];
	struct guest_user guest[size];
	char gameID[30];
	do
	{
		printf("\n1.add_user");	
		printf("\n2.sort");
		printf("\n3.d_order");
		printf("\n4.search_name");
		printf("\n5.inactive_user");
		printf("\n6.active_user");
		printf("\n7.top_5");
		printf("\n0.EXIT");
		printf("\n Enter your choice :");
		scanf("%d",&ch);
		if(ch == 1)
		{
		    add_user();
		}
		if(ch == 2)
		{
			sort(played,size);
		}
		if(ch == 3)
		{
			printf("\nEnter the number of entries:");
			scanf("%d",&n);
			for(i=0;i<n;i++)
	        {
		        printf("\nEnter the Game ID:");
		        scanf("%s",master[i].gameID);
		
		        printf("\nEnter the name:");
		        scanf("%s",master[i].name);
		
		        printf("\nEnter the type:");
		        scanf("%s",master[i].type);
		
	        }
			d_order(master,gameID);
		}
		if(ch == 4)
		{
			search_name(k,M,r,name,gameID);
		}
	    if(ch == 5)
		{
			inactive_user(p,players_count,played,game_count);
		}
		if(ch == 6)
		{
			active_user(info,players_count,k);
		}
	   if(ch == 7)
	   {
	   	    top_5(played,game_count);
	   }
	}while(ch!=0);
	return 0;
}
