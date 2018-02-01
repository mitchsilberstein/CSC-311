#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define WINNING_TICKETS 2110

typedef struct Ticket {
  int ticketID;
  int first;
  int second;
  int third;
  int fourth;
  int fifth;
  int powerball;
  int powerplay;
  char drawDate[10];
} Ticket;

Ticket createTicket(char *line, Ticket ticket)
{
  char drawDate[10];
  int first;
  int second;
  int third;
  int fourth;
  int fifth;
  int powerball;
  int powerplay;

  sscanf(line, "%s" "%d" "%d" "%d" "%d" "%d" "%d" "%d",
        drawDate, &first, &second, &third, &fourth, &fifth, &powerball, &powerplay);
  /**
  printf("%s %d %d %d %d %d %d %d\n",
        drawDate, first, second, third, fourth, fifth, powerball, powerplay);
  */

  strcpy(ticket.drawDate, drawDate);
  ticket.first = first;
  ticket.second = second;
  ticket.third = third;
  ticket.fourth = fourth;
  ticket.fifth = fifth;
  ticket.powerball = powerball;
  ticket.powerplay = powerplay;

  /**
  printf("%s %d %d %d %d %d %d %d\n",
        ticket.drawDate, ticket.first, ticket.second,
	 ticket.third, ticket.fourth, ticket.fifth,
	 ticket.powerball, ticket.powerplay);
  */

  return ticket;
}

int main(int argc, char** argv)
{
  struct Ticket *winningTickets;
  winningTickets = calloc(WINNING_TICKETS, sizeof(struct Ticket));
  if (!winningTickets)
  {
    perror("calloc");
    return -1;
  }

  char *line = NULL;
  size_t lengthOfBuffer = 0;
  ssize_t numberOfCharactersRead;

  FILE * inputStream = fopen("iowa-powerball.txt", "r");

  numberOfCharactersRead = getline(&line, &lengthOfBuffer, inputStream);

  if (numberOfCharactersRead == -1)
  {
    perror("getline()");
  }
  else
  {
    winningTickets[0] = createTicket(line, winningTickets[0]);
    winningTickets[0].ticketID = 0;
  }

  int i = 1;
  while (numberOfCharactersRead > 0)
  {
    numberOfCharactersRead = getline(&line, &lengthOfBuffer, inputStream);

    if (numberOfCharactersRead == -1)
    {
      perror("getline()");
    }
    else
    {
      winningTickets[i] = createTicket(line, winningTickets[i]);
      winningTickets[i].ticketID = i;
      i++;
    }
  }

  fclose(inputStream);

  free(line);


  for (int i = WINNING_TICKETS; i > 0; i--)
  {
    printf("----------------------------------------------\n");
    printf("Ticket ID: %d\n", winningTickets[i].ticketID);
    printf("Draw Date: %s\n", winningTickets[i].drawDate);
    printf("Numbers 1 - 5: %d %d %d %d %d\n", winningTickets[i].first,
	   winningTickets[i].second, winningTickets[i].third,
	   winningTickets[i].fourth, winningTickets[i].fifth);
    printf("Powerball: %d\n", winningTickets[i].powerball);
    printf("Power Play: %d\n", winningTickets[i].powerplay);

  }

//calculating white ball frequency
int lottoNum[70]={0};
for (int i =0; i < WINNING_TICKETS; i++){
  for (int j = 1; j < 70; j++){
  if (winningTickets[i].first == j || winningTickets[i].second == j || winningTickets[i].third == j || winningTickets[i].fourth == j || winningTickets[i].fifth == j){
    lottoNum[j] += 1;
  } // if
} // for
}

  for (int c = 1 ; c <= 69 ; c++){
    printf("%d  -->  %d\n", c, lottoNum[c]);
  } // for







  free(winningTickets);

  return 0;
}
