/*
 * A basic menu based structure has been provided
*/

#include "q1.h"
//Our Linked List Node

/* function will display the primary user interface
    This is already done for you*/
void prompt(){

  printf("1. Add a new car to the available-for-rent list,\n");
  printf("2. Add a returned car to the available-for-rent list,\n");
  printf("3. Add a returned car to the repair list,\n");
  printf("4. Transfer a car from the repair list to the available-for-rent list,\n");
  printf("5. Rent the first available car,\n");
  printf("6. Print all the lists,\n");
  printf("7. Quit.\n");
  printf("Enter your choice: ");
}

/**
 * Inserts a new car into the linked list.
 * @param head Pointer to the head of the list.
 * @param plate Character array containing the car's license plate.
 * @param mileage Integer representing the car's mileage.
 * @param return_date Integer representing the car's return date, you can have -1 represent no return date.
 * @return Pointer to the newly added car in the list.
 */
struct car * insert_to_list(struct car ** head, char plate[], int mileage, int return_date){

    struct car * new_node = malloc(sizeof(struct car)); //allocate memory for new car node
    strcpy(new_node->plate, plate); //copying the plate number into struct member plate
    new_node->mileage = mileage;
    new_node->return_date = return_date;

    //adding new_node car to the linked list at the begginning

    new_node->next = *head; //new node will point to node pointed by head at the moment
    *head = new_node; //head pointer will point to new node

    return new_node; //return pointer;
}

/**
 * Prints all the cars in the list.
 * @param head Pointer to the head of the list.
 * This function prints out the car details, it should not print return date if it does not exist.
 */
void print_list(struct car *head){

     //check if pointer is not null at the first place.
     while (head != NULL){

         //print current car node details.
         printf("The car plate is:%s\n", head->plate);
         printf ("The car mileage is: %d\n", head->mileage);

         //if head = -1 it means it doesnt exist
         if (head->return_date != -1){
           printf ("The return date is %d\n", head->return_date);
         }
         //move on to next node
         head = head->next;
     }
     printf ("\n"); //to seperate lists
     return;
}

/**
 * Checks if a car's plate is already in the list.
 * @param head Pointer to the head of the list.
 * @param plate Character array containing the car's license plate.
 * @return Boolean value indicating if the plate is found.
 */
bool is_plate_in_list(struct car * head, char plate[]){

      char input_plate[9];
      char temp_head_plate[9]; // Assuming plates have a max length of 8 characters + null terminator

      strcpy (input_plate, plate);
      //make sure comparision is case insensitive
      for (int i = 0; i < strlen(input_plate); i++){
         input_plate[i] = tolower(input_plate[i]);
      }

     while (head != NULL){          //if head  is null meaning empty LL

           strcpy (temp_head_plate, head->plate);

          for (int i = 0; i <strlen(temp_head_plate); i++){
             temp_head_plate[i] = tolower(temp_head_plate[i]);
          }

//IMPORTANT ***compare both lowercase
          if (strcmp (input_plate, temp_head_plate) == 0){ //if plate exists in link list result will be 0.
            return true;
          }
          //if not move on to the next node in the linked list
          head =head->next;
     }

     return false;

}

/**
 * Swaps two cars in the list.
 * @param a Pointer to the first car.
 * @param b Pointer to the second car.
 * Swaps the plate, mileage, and return date of two cars.
 */
void swap(struct car *a, struct car *b){


    char plate [9];
    int mileage, return_date; //Return date should be -1 for a car with no return date

    if (a == NULL || b == NULL || a == b){ //if a or b are null pointers, or a and b point to the same node
      return;
    }
   //store the plate,mileage and return date for the first car node
    strcpy (plate, a->plate);
    mileage = a->mileage;
    return_date =  a->return_date;

    //put the plate mileage and return date of the second car into the first car node
    strcpy(a->plate, b->plate);
    a->mileage = b->mileage;
    a->return_date = b->return_date;

    //put the plate,mileage and return date of the first car into the second car node
    strcpy(b->plate, plate);
    b->mileage = mileage;
    b->return_date = return_date;

}

/**
 * Sorts the list of cars based on mileage or return date.
 * @param head Pointer to the head of the list.
 * @param sort_by_mileage Boolean to sort by mileage.
 * @param sort_by_return_date Boolean to sort by return date.
 */
void sort_list(struct car ** head, bool sort_by_mileage, bool sort_by_return_date){

    if (*head == NULL || (*head)->next == NULL ){ //if list is empty or 1 node
      return;
    }
    //variables needed
    bool swap_needed;
    struct car *nextNode = NULL;
    struct car *previousNode = NULL;
    int swapFound = 1; //to be able to enter the while loop 
    struct car * temp =NULL;

    while (swapFound){

        swapFound = 0; //no swaps yet
        temp = *head; //to iterate over the list without changing the head unless needed
        previousNode = NULL; //reseting it with temp to repeat again if swap is found
        while (temp->next != NULL){

             nextNode = temp->next; //next will point on to the next node

              swap_needed = false;
              if (sort_by_mileage && sort_by_return_date){ //if both are true
                printf ("You cannot sort by both return date and mileage.\n");
                return;
              }

              //check what variable do we sort the list based on.
              if(sort_by_mileage){
                swap_needed = (temp->mileage > nextNode->mileage);
              }
              else if (sort_by_return_date){
                swap_needed = (temp->return_date > nextNode->return_date);
              }
              else {
                  return;
              }

             if (swap_needed){
                  if (temp == *head){ //special case: first node

                    temp->next = nextNode->next;
                    nextNode->next = temp;
                    *head = nextNode; //update head
                  }
/*
                  else if (nextNode->next == NULL){ //sepcial case: last node

                      previousNode->next = next;
                      nextNode->next = temp;
                      temp->next = NULL;

                  }
*/
                  else{ //if the node is just in the middle of a link list

                      previousNode->next =nextNode;
                      temp->next = nextNode->next;
                      nextNode->next = temp;

                  }
                  swapFound = 1; //we found a swap thus we go again through while loop
                  previousNode = nextNode;

             } //outer if loop

             else { //the current return date or mileage value is not larger than next mielage or return date value
                  previousNode = temp;
                  temp = nextNode;
             }
        } //inner while loop


   } //outer while loop
}

/**
 * Removes a car from the list by its plate number.
 * @param head Pointer to the head of the list.
 * @param plate Character array containing the car's license plate.
 * @return Pointer to the removed car.
 */
struct car * remove_car_from_list(struct car **head, char plate[]){
    struct car * temp = NULL;
    struct car * previousNode = NULL;

      char input_plate[9];
      char temp_head_plate[9]; // Assuming plates have a max length of 8 characters + null terminator

      strcpy (input_plate, plate);
      //make sure comparision is case insensitive
      for (int i = 0; i < strlen(input_plate); i++){
         input_plate[i] = tolower(input_plate[i]);
      }


    if (*head == NULL){
      return NULL; //empty linked list
    }

    temp = *head;

    while (temp != NULL){
         //ensure comparision is case insensitive
         strcpy (temp_head_plate, temp->plate);
         for (int i=0; i < strlen (temp_head_plate); i++){
            temp_head_plate[i] = tolower(temp_head_plate[i]);
         }

         if (strcmp (input_plate, temp_head_plate) == 0){
           if (temp == *head){ //if first element plate number equals plate
             *head = temp->next; //head will points to the 2nd element in the node will be the first eventually
           }

//           else if (temp->next == NULL){
  //           previousNode->next = NULL;
    //       }

           else {
             previousNode->next = temp->next; // point before node to the after node and remove middle node
           }
           return temp;

        } //if loop
         previousNode = temp;
         temp = temp->next;

}
return NULL; //plate not found;
}

/**
 * Removes the first car from the list.
 * @param head Pointer to the head of the list.
 * @return Pointer to the removed car.
 */
struct car * remove_first_from_list(struct car **head){

    struct car * temp = *head;
    if (*head == NULL){
      return NULL;
    }

    *head = temp->next; // Move the head to the next car in the list

    return temp; //return removed car node

}

/**
 * Calculates the profit based on the mileage difference.
 * @param initial_mileage Integer representing the car's starting mileage.
 * @param final_mileage Integer representing the car's final mileage.
 * @return Double value representing the calculated profit.
 */
double profit_calculator(int initial_mileage, int final_mileage){
    double total_mileage, profit;

    total_mileage = final_mileage - initial_mileage;
    if (total_mileage <= 200){ //if mileage is than 200 or equal to, flat rate of 80$
      profit = 80;
    }

    else { //if mileage is more than 200, we charge 0.15 on every extra km after 200

       profit = ((total_mileage - 200) * 0.15) + 80;

    }
    return profit;
}

/**
 * Writes the list of cars to a file.
 * The file would be in the format: plate,mileage,return_date
 * @param filename Character array with the file name.
 * @param head Pointer to the head of the list.
 * Writes the details of each car in the list to a file.
 */
void write_list_to_file(char *filename, struct car *head){

    //open the file
    FILE * file = fopen(filename, "w");

    if (file == NULL) {
      printf("Error opening file: %s\n", filename);
      return; // or handle the error as needed
    }

    //check if head is null in the first pllace
    // go over the linked list and write each node to the file

    while (head != NULL){
         //write plate,mileage,return_data to filename
         fprintf (file, "%s,", head->plate);
         fprintf (file, "%d,", head->mileage);
         fprintf (file, "%d\n", head->return_date);

         //move head to next node
         head = head->next;
    }
    fclose (file);
    return;
}

/**
 * Reads car details from a file and adds them to the list.
 * The file would be in the format: plate,mileage,return_date
 * @param filename Character array with the file name.
 * @param head Pointer to the head of the list.
 * Reads data from the file and inserts each car into the list.
 */
void read_file_into_list(char *filename, struct car **head){

    char plate[9];
    int mileage, return_date;
    struct car * new_car; //for allocating new node memory
    struct car * temp = NULL;
    char *newline_pos;

    //open the file
    FILE * file = fopen(filename, "r");

    if (file == NULL) {
      printf("Error opening file: %s\n", filename);
      return; // or handle the error as needed
    }

  while ((fscanf (file, " %8[^,],%d,%d", plate, &mileage, &return_date)) == 3){ //scan 3 fields sepearted by commas and ignore the newline char

      //printf("Read: Plate = %s, Mileage = %d, Return Date = %d\n", plate, mileage, return_date); //for testing purposes
      if ((newline_pos = strchr(plate, '\n')) != NULL) { //remove the \n in the plate included by the scanf by placing it with \0
           *newline_pos = '\0';  // Trim the newline character
      }

      new_car = malloc (sizeof(struct car));
      strcpy(new_car->plate, plate);
      new_car->mileage = mileage;
      new_car->return_date = return_date;
      new_car->next = NULL;

      if (*head == NULL){ //first time reading head points at the first node
          *head = new_car; //create a new linked list with head pointed on new_car
       }

      else {
          temp = *head;
          //transverse the list if their is elements so we can add at the end.
          while (temp->next != NULL){
          temp = temp->next;
          }
          temp->next = new_car;
      }

   }
    fclose(file);
    return;
}

/**
 * Prints the date in the format of year/month/day.
 * @param date Integer representing the date in YYMMDD format.
 */
void date(int date){

    int year,month,day;
    year = (date / 10000) %100; //gets us the last 2 digits - eason told me dont include all four
    month = (date /100) % 100; // get the middle digits since date/100 gets rid of last two digits and %100 gives us the middle 2 values
    day = date % 100; //get the last 2 digits

    printf ("%02d/%02d/%02d\n", year,month, day);

}

/**
 * Frees all the memory allocated for the cars in the list.
 * @param head Pointer to the head of the list.
 * Frees each car node in the list.
 */
void free_list(struct car ** head){

    struct car * temp;

    while (*head != NULL){
        temp = *head; //temp = head
        *head = (*head)->next; //move on to next node
        free(temp); //free current node
    }
    return;
}
