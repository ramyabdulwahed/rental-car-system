/*
 * This is the main file for the assignment
*/
#include "q1.h"
//#include "q1_functions.c"
/*
 * A basic menu based structure has been provided
*/

int main(){

    int current_mileage, mileage, return_date, isPlateValid, plateExists, day, month, validDate;
    char plate[9];
    //filenames
    char availableC_filename[14];
    char rentedC_filename[11];
    char repairC_filename[11];

    // set each filename
    strcpy (availableC_filename, "available.txt");
    strcpy (repairC_filename, "repair.txt");
    strcpy (rentedC_filename, "rented.txt");


    double profit;
    struct car * removedCar;

    //Our three Linked Lists
    struct car *available_head = NULL;
    struct car *rented_head = NULL;
    struct car *repair_head = NULL;

    int choice;
     read_file_into_list(availableC_filename, &available_head);
     read_file_into_list(repairC_filename, &repair_head);
     read_file_into_list(rentedC_filename, &rented_head);


    do
    {

        prompt();

        //printf("Enter a Choice: ");
        scanf("%d", &choice);

        /*
         * You will need to add all the cases
         * Call the appropriate functions
         * You would also need to save data to disc upon exit
         * File Format: plate,mileage,return_date
         * Error Handling needs to happen too
        */

        switch (choice){

              case 1:
                do{

                  isPlateValid = 1; //assume plate i valid for now
                  plateExists = 0; //assume it doesn't exist
                  printf ("required format of a car plate number: requirement for plate number is a length of 2-8 characters with only numbers and letters, capitalization does not matter.\n");
                  printf ("Enter the plate number: ");
                  scanf ("%s", plate); //sinc plate is already an array=pointer no need for &
                  //check if plate meets requirements
                  if (strlen(plate) < 2 || strlen(plate) > 8){
                        printf ("Plate doesn't meet required length\n");
                        isPlateValid = 0; //invalid plate number
                   }
                  // else {
                   for (int i = 0; i < strlen(plate); i++){
                      if (!(isdigit(plate[i]) || isalpha(plate[i]))){ //if a plate[i]is not a number or char.
                          printf ("Invalid plate number. Plates can have only characters & numbers.\n");
                           isPlateValid = 0;
                            break;
                      }

                    }
                       //check if plate already exists
                       if (is_plate_in_list (available_head,plate)){
                         printf ("PLate number already exists, enter a new plate number.\n");
                         plateExists = 1; //plate is in list
                       }
                 //}
                 }while (!isPlateValid && !plateExists);

                 printf ("Valid plate number entered. \n");

                  printf ("Enter the current total mileage: ");
                  scanf ("%d", &mileage);
                  return_date = -1; //since its only valid for the rented list
                  //add the detail to the available head linked list
                  insert_to_list (&available_head, plate, mileage, return_date);
                  sort_list(&available_head, 1,0);

                  break;

              case 2:

                  printf ("Enter the plate number: ");
                  scanf ("%s", plate);
//                  printf ("\nEnter the current total mileage: ");
  //                scanf ("%d", &current_mileage);

                  if (is_plate_in_list(rented_head, plate)){
                    removedCar = remove_car_from_list (&rented_head, plate);
                    //extract the details from the pointer to be able to use the insert_to_list function
                    mileage = removedCar->mileage;
                    strcpy(plate, removedCar->plate);
                    return_date = -1; //since by default its -1. recall that return_date is only avaliable for rented list.

                    insert_to_list(&available_head, plate,mileage,return_date); //this will add car back to available list
                    printf ("The car with following plate: %s, is transferred from rented cars list to the available cars list", plate);
                 }

                  printf ("\nEnter the current total mileage: ");
                  scanf ("%d", &current_mileage);
                  //input validation for current total mileage.
                  while (current_mileage < removedCar->mileage){ //compare current total mileage and initial mileage, if smaller keep asking user
                       printf ("Invalid input. Current total mileage cannot be less than initial mileage.\n");
                       printf ("Enter a valid current total mileage: ");
                       scanf ("%d", &current_mileage);
                  }


                  //charge is computed and printed.
                  profit =profit_calculator (removedCar->mileage ,current_mileage);
                  printf ("Charge = $%lf\n", profit);
                  sort_list(&available_head, 1,0);

                   break;

              case 3:

                  printf ("Enter the plate number: ");
                  scanf ("%s", plate);
//                  printf ("\nEnter the current total mileage: ");
  //                scanf ("%d", &current_mileage);

                  if (is_plate_in_list(rented_head, plate)){
                    removedCar = remove_car_from_list (&rented_head, plate);
                    //extract the details from the pointer to be able to use the insert_to_list function
                    mileage = removedCar->mileage;
                    strcpy(plate, removedCar->plate);
                    return_date = -1; //since by default its -1. recall that return_date is only avaliable for rented list.

                    insert_to_list(&repair_head, plate,mileage,return_date); //this will add car back to available list
                    printf ("The car with following plate: %s, is transferred from rented  cars list to the repair cars list", plate);
                  }
                  printf ("\nEnter the current total mileage: ");
                  scanf ("%d", &current_mileage);
                  //input validation for current total mileage.
                  while (current_mileage < removedCar->mileage){ //compare current total mileage and initial mileage, if smaller keep asking user
                       printf ("Invalid input. Current total mileage cannot be less than initial mileage.\n");
                       printf ("Enter a valid current total mileage: ");
                       scanf ("%d", &current_mileage);
                  }


                  //charge is computed and printed.
                  profit =profit_calculator (removedCar->mileage ,current_mileage);
                  printf ("Charge = $%lf\n", profit);

                  break;

              case 4:
                  printf ("Enter the plate number: ");
                  scanf ("%s", plate);

                  if (is_plate_in_list(repair_head, plate)){
                    removedCar = remove_car_from_list (&repair_head, plate);
                    //extract the details from the pointer to be able to use the insert_to_list function
                    mileage = removedCar->mileage;
                    strcpy(plate, removedCar->plate);
                    return_date = -1; //since by default its -1. recall that return_date is only avaliable for rented list.

                    insert_to_list(&available_head, plate,mileage,return_date); //this will add car back to available list

                    printf ("The car with following plate: %s, is transferred from repaired cars list to the available cars list", plate);

                  }
                  else {
                    printf ("Car plate doesnt exist\n");
                  }

                  sort_list(&available_head, 1,0);

                  break;

              case 5:
                    sort_list(&available_head, 1,0);

                    validDate = 0; //assume date is invalid
                    //remove the first car in the available list to transfer it to the rented list
                    removedCar = remove_first_from_list (&available_head);

                  //check if the return date is valid. valid date -> month is 1-12, the day is 1-31.
                    do {
                      printf ("Enter the expected return date (yymmdd): ");
                      scanf ("%d", &return_date);
                      month = (return_date /100) % 100; // get the middle digits since date/100 gets rid>
                      day = return_date % 100; //get the last 2 digits

                      if ((month >= 1 && month <=12 ) && (day >=1 && day<=31)){
                        validDate = 1;
                      }
                      else {
                         printf ("Invalid return date entered\n");
                      }
                    } while (!validDate); //if the validDate is =1, not true is false so we exit the loop which means valid date.
                    printf ("Valid return date entered.\n");

                    removedCar->return_date = return_date;
                    //lets add the car to the rented list. it will have a return date
                    insert_to_list(&rented_head, removedCar->plate,removedCar->mileage,removedCar->return_date);
                    printf ("The car with following plate: %s, is transferred from available cars list to the rented cars list", removedCar->plate);

                    break;
              case 6:

                    print_list(available_head);
                    print_list(repair_head);
                    print_list(rented_head);
//                    print_list(repair_head);

                    break;

              case 7:

                  break;


              default: //incase anything invalid is entered we exit the program

                  break;
        }
        
    } while (choice != 7);
    
    //store data in the files.
    write_list_to_file(availableC_filename, available_head);
    write_list_to_file(repairC_filename, repair_head);
    write_list_to_file(rentedC_filename, rented_head);

    return 0;
}
