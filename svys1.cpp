#include<iostream>
#include<stdlib.h>
#include<fstream>
#include<string.h>
#include<stdio.h>
#include<conio.h>
using namespace std;
char c_name[80];
class item
{
    char cname[80];
    char pname[80];
    int qtty;
    float price;
public:
    item()
    {
        cname[0]='\0';
        pname[0]='\0';
        qtty=0;
        price=0;
    }
    item(char cn[80],char pn[80],int qt,float pr)
    {
        strcpy(cname,cn);
        strcpy(pname,pn);
        qtty=qt;
        price=pr;
    }
    void create_cart();
};




void item::create_cart()
{
    ofstream out("cart.txt",ios::app);
    if(!out)
    {
        cout<<"can't open cart file \n";

    }
    else{
    out<<cname<<endl;
    out<<pname<<endl;
    out<<price<<endl;
    out<<qtty<<endl;
    }


    out.close();


}



void home();
void logo();
void product_select();
void shopkeeper_page1();
void customer_page1();
void electronics();
void books();
void stationery();
void beauty();
void health_care();
void personal_care();
void customer_info();
void display_cart();
 void viewform();
 void bill_total();
 void remove_item();
 void all_bills();
 void feedback();
 void payment();

void logo()
{
    cout<<"\t\t\t\t\t\tWELCOME TO ONLINE SUPERMARKET\n";
    cout<<"\t\t\t\t\t\t...........SVYS..............\n";
    cout<<"\t\t\t\t\t\tMust Have It? We've Got It!\n";
}
void home()
{
    system("cls");
    logo();
    int choice;
    string id;
    MENU:cout<<"Login as:\n\n";
    cout<<"1.Customer\n2.Shopkeeper\n\n";
    cout<<"Enter your choice\n";
    cin>>choice;
    switch(choice)
    {
    case 1:
        viewform();
        break;
    INVALID:case 2:
        cout<<"\nEnter login id\n";
        cin>>id;
        if(id=="su"||id=="SU")
            shopkeeper_page1();
        else
        {
            cout<<"Invalid login id\n\n";
            goto INVALID;
        }
        break;
    default:
        goto MENU;
    }

}
void product_select()
{
    char product[80];
    int avail,qtty,ch,n;
    float price;
        OUTOFSTOCK:cout<<"Which product do you wish to see? Enter its number\n";
        cin>>n;
        n=(n-1)*3;
        ifstream inFile;
        inFile.open("basefile.txt");
        if(!inFile){
        cout << "Unable to open file" << endl;
        exit(1);
        }
        for(int i=0;i<=n;i++)
        {
            inFile.getline(product,80);
        }
        inFile>>price>>avail;
        system("cls");
        logo();
        cout<<product<<endl<<"Price: Rs."<<price<<endl;
        if(avail==0)
                    {
                        cout<<"Out of stock\n";
                        goto OUTOFSTOCK;
                    }


        else{
                LOOP:cout<<"1.Add to cart\n2.Go back\n";
              cin>>ch;
              if(ch==1)
              {
                  REDQTTY:cout<<"Enter quantity\n";
                  cin>>qtty;
                  if(qtty<=avail)
                  {
                      item obj(c_name,product,qtty,price*qtty);
                      obj.create_cart();
                      int c;
                      cout<<"Added to cart\n";
                      LOOP1:cout<<endl<<endl<<"1.View Cart\n2.Continue Shopping\n";
                      cout<<"Enter a choice\n";
                      cin>>c;
                      if(c==1)
                      {
                          display_cart();

                      }
                      else if(c==2)
                      {
                          customer_page1();
                      }
                       else
                       {
                           cout<<"Invalid choice\n";
                           goto LOOP1;
                       }

                  }
                  else
                  {
                      cout<<"Not available. Please reduce quantity\n";
                      goto REDQTTY;
                  }
              }
              else if(ch==2)
              {
                  customer_page1();
              }
               else
               {
                   cout<<"Invalid choice\n";
                   goto LOOP;
               }

            }

}
void customer_page1()
{
    int choice;
    INVALID:system("cls");
    logo();
    cout<<"CATEGORIES:\n\n";
    cout<<"1.Electronics\n2.Books\n3.Stationery\n4.Health Care\n5.Beauty\n6.Personal Care\n7.Home page\n\n";
    cout<<"Select a category by its number\n";
    cin>>choice;
    switch(choice)
    {
    case 1:
        electronics();
        break;
    case 2:
        books();
        break;
    case 3:
        stationery();
        break;
    case 4:
        health_care();
        break;
    case 5:
        beauty();
        break;
    case 6:
        personal_care();
        break;
    case 7:
        system("cls");
        home();
    default:
        goto INVALID;
    }
}

void electronics()
{
    int choice;
    INVALID:system("cls");
    logo();
    cout<<"Select a subcategory\n";
    cout<<"1.Mobiles\n2.TV\n3.Kitchen and Home Appliances\n4.Computers and Laptops\n5.Printers\n6.Cameras\n7.Speakers\n8.Go Back\n";
    cin>>choice;
    system("cls");
    switch(choice)
    {
    case 1:
        cout<<"MOBLIES:\n\n1.Samsung Galaxy J7 Pro\n2.OnePlus 6T\n3.Apple iPhone 6\n4.Redmi 6 Pro\n5.Motorola G4 Play\n";
        break;
     case 2:
        cout<<"TV:\n\n6.Samsung HD LED 24 inches\n7.Micromax HD LED 32 inches\n8.Panasonic HD LED 32 inches\n9.Sony HD LED 24 inches\n10.LG HD LED 32 inches\n";
        break;
     case 3:
        cout<<"KITCHEN AND HOME APPLIANCES:\n\n11.Bajaj Mixer Grinder\n12.Whirlpool Refrigerator\n13.Samsung Washing Machine\n14.Bajaj  Microwave Oven\n15.Prestige Gas Stove\n";
        break;
     case 4:
        cout<<"COMPUTERS AND LAPTOPS:\n\n16.Hp 7th gen i3\n17.Dell Inspiron 6th gen i3\n18.Apple 7th gen i5\n19.Macbook Aircore\n20.Lenovo 6th gen i3\n";
        break;
     case 5:
        cout<<"PRINTERS:\n\n21.HP Deskjet\n22.Canon Pixma\n23.Epson6\n24.Samsung Laser\n25.Brother DCP\n";
        break;
     case 6:
        cout<<"CAMERAS:\n\n26.Canon Powershot\n27.Sony DSC\n28.Nikon D56\n29.GoPro hero4\n30.Olympus\n";
        break;
     case 7:
        cout<<"SPEAKERS:\n\n31.Philips BT40\n32.JBL Go\n33.iBall SoundWave\n34.Intex IT301\n35.SONY SRS-XB10\n";
        break;
     case 8:
        customer_page1();
        break;
     default:
        goto INVALID;
    }
    if(choice>=1 &&choice<=7)
        product_select();

}

void books()
{
    int choice,ch;
    string product;
    int avail,qtty,price;
    INVALID:system("cls");
    logo();
    cout<<"Select a subcategory\n";
    cout<<"1.Literature and Fiction\n2.Non Fiction\n3.Children Books\n4.Test Preparation And Guides\n5.Textbooks\n6.Go Back\n";
    cin>>choice;
    system("cls");
    switch(choice)
    {
    case 1:
        cout<<"LITERATURE AND FICTION:\n\n36.Harry Potter-J K Rowling\n37.The Alchemist-Paulo Coelho\n38.The Fault in our Stars-John Green\n39.This Is Not Your Story-Savi Sharma\n40.Will You Still Love Me?-Ravinder Singh\n";
        break;
     case 2:
        cout<<"NON FICTION:\n\n41.The Power of your Subconscious Mind-Joseph Murphy\n42.Mein Kampf-Adolf Hitler\n43.Forge your Future-A.P.J. Abdul Kalam\n44.Captain Cool: The M.S. Dhoni Story-Gulu Ezekeil\n45.The Famous Five-Enid Blyton\n";
        break;
     case 3:
        cout<<"CHILDREN BOOKS:\n\n46.Wolvarine-Paul Jenkins\n47.Panchtantra\n48.Sudhamurty\n49.Malgudi Adventures\n50.Akbar Birbal\n";
        break;
     case 4:
        cout<<"TEST PREPARATION AND GUIDES:\n\n51.JEE Mains-Crack in 5 days\n52.BITSAT-Crack in 1 day\n53.GRE guide\n54.NCERT guides\n55.GATE\n";
        break;
     case 5:
        cout<<"PRINTERS:\n\n56.Grade 8\n57.Grade 9\n58.Grade 10\n59.Grade 11\n60.Grade 12\n";
        break;
     case 6:
        customer_page1();
        break;
     default:
        goto INVALID;
    }
    if(choice>=1 &&choice<=5)
        product_select();

}

void stationery()
{
    int choice;
    INVALID:system("cls");
    logo();
    cout<<"Select a subcategory\n";
    cout<<"1.Diaries and Notebooks\n2.Art Supplies\n3.School Stationery\n4.Go Back\n";
    cin>>choice;
    system("cls");
    switch(choice)
    {
    case 1:
        cout<<"DIARIES AND NTEBOOKS:\n\n61.Notebook 100 pgs\n62.Notebook 200 pgs\n63.Contact list diary\n64.Folders-Pack of 10\n65.Sticky notes-Pack of 2\n";
        break;
     case 2:
        cout<<"ART SUPPLIES:\n\n66.Water colours-18 shades\n67.Sketchpens-12 shades\n68.Wax Crayons-24 shades\n69.Colour pencils-24 shades\n70.Sketch pencils set\n";
        break;
     case 3:
        cout<<"SCHOOL STATIONERY:\n\n71.Pens-Pack of 10(Blue)\n72.Pencils-Pack of 20\n73.Erasers-Pack of 20\n74.Geometry box\n75.Calculator\n";
        break;
     case 4:
        customer_page1();
        break;
     default:
        goto INVALID;
    }
    if(choice>=1 &&choice<=3)
        product_select();
}
void health_care()
{
    int choice;
    INVALID:system("cls");
    logo();
    cout<<"Select a subcategory\n";
    cout<<"1.Sport Supplements\n2.Family Nutrition\n3.Medicines\n4.Handwash\n5.Go Back\n";
    cin>>choice;
    system("cls");
    switch(choice)
    {
    case 1:
        cout<<"SPORT SUPPLEMENTS:\n\n76.Glucose Supplement\n77.Protein Supplement\n78.Boost-The secret of my energy\n79.Protinex\n";
        break;
     case 2:
        cout<<"FAMILY NUTRITION:\n\n80.Cornflakes\n81.Oats\n82.Chocos\n83.Bournvita-Badhae doodh ki shakti\n84.Horlicks\n";
        break;
     case 3:
        cout<<"MEDICINES :\n\n85.Soframycin\n86.DOLO\n87.Ultracet\n88.Azithromycin\n89.Moov\n";
        break;
     case 4:
        cout<<"HANDWASH:\n\n90.Dettol\n91.Lifebuoy\n92.Dove\n93.Patanjali\n94.Palmolive\n";
        break;
     case 5:
        customer_page1();
        break;
     default:
        goto INVALID;
    }
    if(choice>=1 &&choice<=4)
        product_select();

}
void beauty()
{
    int choice;
    INVALID:system("cls");
    logo();
    cout<<"Select a subcategory\n";
    cout<<"1.Makeup\n2.Skin Care\n3.Hair Care and Styling\n4.Fragrance\n5.Go Back\n";
    cin>>choice;
    system("cls");
    switch(choice)
    {
    case 1:
        cout<<"MAKEUP:\n\n95.Facial kit combo\n96.Mac lipstick\n97.Colossal kajal\n98.Makeup kit\n99.Lakme Foundation\n";
        break;
     case 2:
        cout<<"SKIN CARE:\n\n100.Nivea cocoa cream\n101.Vaseline petroleum jelly\n102.Himalaya Face Wash\n103.Lotus Sunscreen\n104.Lux soap\n";
        break;
     case 3:
        cout<<"HAIR CARE AND STYLING :\n\n105.Nivea Hair wax\n106.Axe hair gel\n107.Parachute oil\n108.L'Oreal Paris Total Repair 5 Shampoo\n109.Livon hair serum\n";
        break;
     case 4:
        cout<<"FRAGRANCE:\n\n110.Axe\n111.Wild stone\n112.Engage\n113.Fogg\n114.Set Wet\n";
        break;
     case 5:
        customer_page1();
        break;
     default:
        goto INVALID;
    }
    if(choice>=1 &&choice<=4)
        product_select();

}



void personal_care()
{
    int choice;
    INVALID:system("cls");
    logo();
    cout<<"Select a subcategory\n";
    cout<<"1.Shaving Care\n2.Feminine Hygiene\n3.Go Back\n";
    cin>>choice;
    system("cls");
    switch(choice)
    {
    case 1:
        cout<<"SHAVING CARE:\n\n115.Philips Beard Trimmer\n116.Ustraa Beard Oil\n117.Razor blade\n118.Epilator\n119.Shaving cream\n";
        break;
     case 2:
        cout<<"FEMININE HYGIENE:\n\n120.Whisper Ultra Thin Napkin\n121.Stayfree All Night Napkin\n122.Stayfree Day Thick Napkin\n123.Tampons-Pack of 10\n124.Intimate Wash\n";
        break;
     case 3:
        customer_page1();
        break;
     default:
        goto INVALID;
    }
    if(choice>=1 &&choice<=2)
        product_select();
}


void viewform()
{
    system("cls");
    logo();
    char name[80];
    long long pno;
    char add[80];
    cout<<endl<<endl<<endl;
    cout<<"******************************************************CUSTOMER DETAILS**************************************************\n"<<endl<<endl;
    cout<<"Enter your details: \n"<<endl;
    cout<<"Enter your name:\n";
    fflush(stdin);
    gets(name);
    cout<<endl;
    cout<<"Enter your phone number:\n";
    cin>>pno;
    cout<<endl;
    cout<<"Enter your address:\n";
    fflush(stdin);
    gets(add);
    cout<<endl;
    strcpy(c_name,name);
    ofstream out("form.txt",ios::app);
    out<<name<<endl;
    out<<pno<<endl;
    out<<add<<endl;
    out.close();
    customer_page1();
}

void shopkeeper_page1()
{
    int choice;
    INVALID:system("cls");
    logo();
    cout<<"1.Review Customer Information\n2.Review Today's Sales\n3.Go Home\n";
    cin>>choice;
    switch(choice)
    {
    case 1:
        customer_info();
        break;
    case 2:
        all_bills();
        break;
    case 3:
        home();
        break;
    default:
        goto INVALID;
    }
}

void all_bills()
{
    system("cls");
    char line[80];
    ifstream in("bills.txt",ios::in);
    while(!in.eof())
    {
        in.getline(line,80);
        cout<<line<<endl;
    }
    in.close();
    getch();
    shopkeeper_page1();

}


void customer_info()
{
    system("cls");
    cout<<"Customer Info\n\n";
    ifstream in("form.txt",ios::in);
    if(!in)
    {
        cout<<"can't open file \n";
    }
    else{
        char name[80],contactno[80],address[80],ch[80];
        cout<<"NAME"<<"\t\t\t\t"<<"CONTACT NO"<<"\t\t\t\t"<<"ADRRESS"<<endl<<endl<<endl<<endl;
        while(!in.eof())
        {
        in.getline(name,80);
        in.getline(contactno,80);
        in.getline(address,80);
        cout<<name<<"\t\t\t\t"<<contactno<<"\t\t\t\t"<<address<<endl<<endl;
        }
    }

    in.close();
    getch();
    shopkeeper_page1();

}

void display_cart()
{
    system("cls");
    logo();
    cout<<endl<<endl;
    cout<<"..........................................................CART.........................................................";
    cout<<endl<<endl;
    int choice;

    ifstream in("cart.txt",ios::in);
    float price;
    char s[80], s1[80], s2[80];
    cout<<c_name<<endl<<endl;
    while(!in.eof())
    {
        in.getline(s,80);
        if(strcmp(s,c_name)==0)
        {
            in.getline(s1,80);cout<<"Product: "<<s1<<endl;//read pname
            in.getline(s2,80);cout<<"Total Price: "<<s2<<"\n";//read price
            in.getline(s,80);cout<<"Quantity: "<<s<<"\n\n";

        }


    }
    in.close();
   INVALID: cout<<endl<<endl<<"1. Add more items\n2.Remove from cart\n3.Generate bill\n";
   cout<<"Enter your choice";
   cin>>choice;
   switch(choice)
   {
   case 1:
    customer_page1();
    break;
   case 2:
       remove_item();
       break;
   case 3:
    bill_total();
    payment();
    break;
   case 4:
    goto INVALID;

   }
}


void bill_total()
{
    system("cls");
    logo();
    cout<<endl<<endl;
    cout<<".....................................................BILL...................................................";
    cout<<endl<<endl;
    ifstream in("cart.txt",ios::in);
    ofstream out("bills.txt",ios::app);
    out<<c_name<<endl;
    float total=0.0,price;
    char s[80], s1[80], s2[80];
    while(!in.eof())
    {
        in.getline(s,80);
        if(strcmp(s,c_name)==0)
        {
            in.getline(s1,80);cout<<s1<<": Rs.";//read pname
            in.getline(s2,80);//cout<<"got price\n";//read price
            price=atof(s2);cout<<price<<endl;
            total+=price;
            out<<s1<<" : "<<"Rs."<<s2<<endl;
        }


    }
    in.close();
    out<<"Total: Rs"<<total<<endl<<endl;
    cout<<"\n\nTotal Amount: Rs."<<total<<endl;
    getch();

}


void remove_item()
{
    char p[80], s[80],s1[80],s2[80],s3[80];
    cout<<"Which order do you want to cancel?";
    fflush(stdin);
    gets(p);
    fstream in("cart.txt",ios::in);
    while(!in.eof())
    {
        in.getline(s,80); //cname
        if(strcmp(s,c_name)==0)
        {
            in.getline(s1,80); //pname
            in.getline(s2,80); //price
            in.getline(s3,80); //qty
            if(strcmp(s1,p)!=0)
            {
                 ofstream out("Updated.txt",ios::app);
                 if(out)
                 {
                     out<<s<<endl;
                     out<<s1<<endl;
                     out<<s2<<endl;
                     out<<s3<<endl;
                 }
                 out.close();

            }
        }
    }
    in.close();

    remove("cart.txt");
    rename("Updated.txt","cart.txt");
    display_cart();

}

void payment()
{
    int a;
    cout<<"Enter mode of payment: \n1.Matercard\n2.COD\n3.Paytm\n";
    cin>>a;
    cout<<"Payment successful\n";
    system("cls");
    logo();
    feedback();

}

void feedback()
{
    int rate;
    system("cls");
    logo();
    INVALID:cout<<"\n\nShare your shopping experience\n\nRate us out of 5\n\n";
    cin>>rate;
    switch(rate)
    {
    case 1:
    case 2:
        cout<<"We're sorry for your inconvenice..Looking forward to improve!";
        break;
    case 3:
    case 4:
        cout<<"Working on improvements..Have a nice day!";
        break;
    case 5:
        cout<<"Glad you liked it..Hope to see you soon!";
        break;
    default:
        cout<<"Please rate out of 5";
        goto INVALID;
    }
    getch();
    home();
}
int main()
{
    home();
    return 0;
}
