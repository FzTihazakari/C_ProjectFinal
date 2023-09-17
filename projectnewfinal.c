#include <stdio.h>

float totalprice(float a);

struct Order{
	int order;
	int quantity;
	int addon;
	int addquantity;
	};

int main(){
	
	char name[20];
	char menu[][25]={"Birthday Cake","Pancake","Cookie","Coffee","Brownies","Hot Pudding","Chocolate Ice Cream","Grain Breads","Cold Drinks"};
	char addmenu[][50]={"Ballons","Flower Bouquet","Gift Card","Premium Chocolate"};
	float price[9]={75.00,10.00,5.00,8.00,7.00,8.00,3.00,9.00,2.00}; //array
	float addprice[4]={2.00,10.00,3.00,7.00};
	int value,i,addon, addonchoice,addvalue;
	int cardnumber, method,serve,days;
	float amount,getprice,tprice=0,tquantity=0,priceall=0,pricequantity=0,priceaddon=0,totalgetprice=0,reserveprice=0;
	
	printf("\n\t   Welcome to Bakery System.\n\n");
	printf("\t  Please enter your name : ");
	scanf("%20[^\n]",&name);
	printf("\t\tHello, %s!",name);
	printf("\n\t      How can we help you?");
	printf("\n\t    Take a look at the menu!\n\n");

	printf("\t\t  MENU :\n\n");
	printf("       Item                         Price\t\n");
	printf("1. %s\t\t    %.2f\t \n",menu[0], price[0]);
	printf("2. %s\t\t\t    %.2f\t \n",menu[1], price[1]);
	printf("3. %s\t\t\t     %.2f\t \n",menu[2], price[2]);
	printf("4. %s\t\t\t     %.2f\t \n",menu[3], price[3]);
	printf("5. %s\t\t\t     %.2f\t \n",menu[4], price[4]);
	printf("6. %s\t\t\t     %.2f\t \n",menu[5], price[5]);
	printf("7. %s\t\t     %.2f\t \n",menu[6], price[6]);
	printf("8. %s\t\t\t     %.2f\t \n",menu[7], price[7]);
	printf("9. %s\t\t\t     %.2f\t \n\n",menu[8], price[8]);

	printf("How many orders you would like to make? \n");
	printf("Enter value : ");
	scanf("%d",&value);

	struct Order order[8];

	for (i=0; i<value; i++)
	{
		printf("\nEnter item's number : ");
		scanf("%d",&order[i].order);
		printf("Enter quantity : ");
		scanf("%d",&order[i].quantity);
		tquantity=order[i].quantity*price[order[i].order-1];
		tprice=tprice+tquantity;
		}
	
	for (i=0; i<value; i++)
	{
		printf("\nOrder %d details : ", i+1);
		printf("\nYou've ordered : %d %s.\n", order[i].quantity, menu[order[i].order-1]);
	
	}
	printf("\nDo you want to add on anything?\nEnter 1 for Yes and 2 for No : ");
	scanf("%d",&addon);
		
		if (addon==1){
			printf("\n1.%s\t\t\t    %.2f\t \n",addmenu[0],addprice[0]);
			printf("2.%s\t\t\t    %.2f\t \n",addmenu[1],addprice[1]);
			printf("3.%s\t\t\t    %.2f\t \n",addmenu[2],addprice[2]);
			printf("4.%s\t\t\t    %.2f\t \n",addmenu[3],addprice[3]);
	        printf("\nHow many add on you would like to make? \n");
	        printf("Enter value : ");
	        scanf("%d",&addvalue);
	        
	        for (i=0; i<addvalue; i++){
	          printf("\nEnter item's number : ");
		      scanf("%d",&order[i].addon);
		      printf("Enter quantity : ");
		      scanf("%d",&order[i].addquantity);
		      pricequantity=order[i].addquantity*addprice[order[i].addon-1];
		      priceaddon=priceaddon+pricequantity;
			  priceall=tprice+priceaddon;
		    }
		}
		
		else{
			printf("There are no add ons.");
		}
		printf("\n\nWould you like to take away, dine in or make a reservation?");
		printf("\n1.Take Away");
		printf("\n2.Dine In");
		printf("\n3.Reservation\n");
		
		printf("\n\nEnter number the way you want us to serve you :");
		scanf("%d",&serve);
		
		if(serve==1){
					
	printf("\nPrice :RM%.2f\n",priceall);
	getprice=totalprice(priceall);
	printf("\nYour total price after discount : RM%.2f",getprice);
		
	printf("\n\nWe accept cash and credit card.\nChoose your payment method.");
	printf("\nEnter 1 for cash or 2 for credit card : ");
	scanf("%d",&method);
	
if(method==1){
		printf("\nYour payment method is by cash.");
		printf("\nEnter cash amount : RM ");
		scanf("%f",&amount);
		totalgetprice=amount-getprice;
		printf("\n\nYour balance is RM%.2f",totalgetprice);
	}
	
	else {
		printf("\nYour payment method is by card.");
		printf("\nEnter card number : ");
		scanf("%d",&cardnumber);	
	}
	printf("Thank you for your payment.See you again!");
}
else if(serve==2){
	printf("\nPrice :RM%.2f\n",priceall);
	getprice=totalprice(priceall);
	printf("\nYour total price after discount : RM%.2f",getprice);
		
	printf("\n\nWe accept cash and credit card.\nChoose your payment method.");
	printf("\nEnter 1 for cash or 2 for credit card : ");
	scanf("%d",&method);
	
	if(method==1){
		printf("\nYour payment method is by cash.");
		printf("\nEnter cash amount : RM ");
		scanf("%f",&amount);
		totalgetprice=amount-getprice;
		printf("Your balance is RM%.2f",totalgetprice);
	}
	
	else {
		printf("\nYour payment method is by card.");
		printf("\nEnter card number : ");
		scanf("%d",&cardnumber);	
	}
	printf("\n\nThank you for your payment.Please wait, we will send your food anytime soon.");
	
}
else if(serve==3){
	printf("\nHow many days from your reservation day:");
	scanf("%d",&days);
	if(days>=7){
	  
	printf("\nPrice :RM%.2f\n",priceall);
	getprice=totalprice(priceall);
	reserveprice=getprice*0.95;
	printf("\nYour total price after discount : RM%.2f",reserveprice);
	}
	else if(days<7){
	  printf("\nPrice :RM%.2f\n",priceall);
	  getprice=totalprice(priceall);
	  reserveprice=getprice*1.00;
	  printf("\nYour total price after discount : RM%.2f",reserveprice);
	 
	 	  
	}
	printf("\n\nWe accept cash and credit card.\nChoose your payment method.");
	printf("\nEnter 1 for cash or 2 for credit card : ");
	scanf("%d",&method);
	
	if(method==1){
		printf("\nYour payment method is by cash.");
		printf("\nEnter cash amount : RM ");
		scanf("%f",&amount);
		totalgetprice=amount-reserveprice;
		printf("Your balance is RM%.2f",totalgetprice);
	}
	
	else {
		printf("\nYour payment method is by card.");
		printf("\nEnter your 10 digit card number : ");
		scanf("%d",&cardnumber);	
	}
	printf("\n\nThank you for your payment.Your reservation is confirmed!");
	
}

	return 0;
	
}

float totalprice(float a){
	float total;
	if (a>150){
		total=a*0.9;
	}
	else if (a>120){
		total=a*0.93;
	}
	else if (a>80){
		total=a*0.95;
	}
	else{
		total=a;
	}
	return total;
}
