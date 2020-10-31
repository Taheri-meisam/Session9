// Session9
//I/O
//

#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

// search a file to see how many times a word has been used 
void iomanipBool();
void iomanipIntegers();
void iomanipFloat();
void readFromFile();
void readStory();
void writeToFiles();
void writeToFile2();
// new function copy a binary file 
void copyFile();

void iomanipBool() {
    // it prints 0 or 1
    std::cout << "Defualt :" <<  (10 == 10) <<  std::endl;
    std::cout << "Defualt :" <<  (10 == 20) << std::endl;

    // using I/O stream manipulator we can change the way boolean is printed out 
    std::cout << std::boolalpha;
    std::cout << "boolalpha :" << (10 == 10) <<  std::endl;
    std::cout << "boolalpha :" << (10 == 20) << std::endl;


    //  std::cout << std::noboolalpha; // 1 or 0
    //  std::cout << std::boolalpha;// true or false

    //we can also use method version
  /**/
    std::cout << std::resetiosflags(std::ios::boolalpha);   // std::cout.setf(std::ios::boolalpha);
    std::cout  << "reset to defualt :" << (10 == 10) << std::endl;
    std::cout << "reset to defualt :" << (10 == 20) <<  std::endl;



}


void iomanipIntegers() {
    std::cout << " iomanip Integers " << std::endl;
    int num = 500; 
  
    // printing default 
    std::cout << std::dec << num << std::endl;
    std::cout << std::hex << num << std::endl;
    
    std::cout << std::showbase; // shows the base prefix 
    std::cout << std::dec << num << std::endl;
    std::cout << std::hex << num << std::endl;

    std::cout << std::uppercase; // uppercase the values 
    std::cout << std::dec << num << std::endl;
    std::cout << std::hex << num << std::endl;

    std::cout << std::showpos; // shows the positive sign
    std::cout << std::dec << num << std::endl;
    std::cout << std::hex << num << std::endl;



    /* methods do the same as above just for your information
    std::cout.setf(std::ios::showbase);
    std::cout.setf(std::ios::uppercase);
    std::cout.setf(std::ios::showpos);
      std::cout.setf(std::ios::showbase);
   
    
    */
}


void iomanipFloat() {
    double num = 12345467.23424545445;
    std::cout << num << std::endl;
    std::cout << std::setprecision(2);
    std::cout << std::fixed; // fixed on decimal part 
    std::cout << num << std::endl;
}

void WidthFillAlighn() {
    std::cout.setf(std::ios::dec);
    int number = 1234;
    std::string message = "This is a test message";
    std::cout << number << message <<std::endl;

    std::cout << std::setfill('*') << std::setw(10) << number << std::setfill('#') << std::setw(25) << message << std::endl; 
    //right justified mesage is with lengh of 23 counting from right to left we have a 25 width which means there will be only 2 spaces
    // you can add std::right. it's default and you don't need to add it in the above example 
    // setfill fills the blank space with specific char 
    std::cout << std::left << std::setfill('*') << std::setw(10) << number << std::setfill('#') << std::setw(25) << message << std::endl;


}



void readFromFile() {
  

    // to  add a file . right click on resources and add a txt file
    std::fstream File("story.txt", std::ios::in);  // std::fstream File {"../story1.txt", std::ios::in};
   // if file exist and its open
    if (File) {
     //   std::cout << "File exist";
        perror("File exist");

    }
    else {
        // if file doesn't exist or there was a problem with opening it
        perror("Bstory.txt  ");
       // std::cout << "File Does not exist exist";
     
    }
  
  //second method 

    std::ifstream File2;
    std::string filename = "story2.txt";
    int counter = 0;
    // or you can ask use to enter the file name 
    //std::cin >> filename;

    // on default the file is open for reading 
    File2.open(filename); // File2.open(filename, std::ios::in); 
   
    
    if (File2.is_open()) {
        perror("File2 exist");

    }else{
        perror("File2  ");
    }

    int num = {};
    std::string country;
    char ch{};
    std::cout << " Num : " << num << "Country : " << country << " char : " << ch << std::endl;
    std::fstream TestFile("TestFile.txt", std::ios::in);  // "C:\\github\\TestFile.txt"
    if (TestFile.is_open()) {
        perror("TestFile exist");
        while (TestFile >> num >> country >> ch) {
            
            // TestFile >> country;
             //TestFile >> ch;
            std::cout << " Num : " << num << "Country : " << country << " char : " << ch << std::endl;
            counter++;
        }
    }
    else {
        perror("TestFile ");
    }

    
    std::cout << "counter : " << counter << std::endl;
    //closing the files
    File.close();
    File2.close();
    TestFile.close();
   
}

void readStory() {
    std::string Buffer = "";
    char ch;
    std::fstream StroyFile("story.txt", std::ios::in);  
    if (StroyFile) {
        perror("StroyFile exist"); 
      //  std::cerr << "StroyFile exist " <<std::endl;
        while (!StroyFile.eof()) {                          /// while (std::getline(Storyfile,Buffer)
            std::getline(StroyFile, Buffer);    // read char   ///  StroyFile.get(ch);
            std::cout << Buffer << std::endl;        
        }
    }else {
       
        perror("StroyFile  ");
        //std::cerr << "StroyFile  " << std::endl;
      
    }
    StroyFile.close();
}


void writeToFiles() {
    int num = 2000;
    std::string name = "Honey";
    char ch = 'E';

    std::fstream MyFile("Myfile.txt", std::ios::out); // creates a file if it doesn't exit or overwrite the excist file
    std::fstream MyFile2("Myfile2.txt", std::ios::out | std::ios::app); // creates a file if it doesn't exit or overwrite the excist file
    // std::ios::trunc       truncate is default 
    // std::ios::app  // append on each write 
    // std::ios::ate // you can move or seek the pointer to the location you want 
   
    MyFile << num <<std::endl;
    MyFile2 << name << std::endl;
    MyFile.put(ch);
    MyFile.close();
    MyFile2.close();



}

void writeToFile2() {
    std::string inputText;
    
    std::ofstream outFile("outFile.ini"); // std::ofstream outFile("outFile.txt" , std::ios::app);
    if (!outFile) {
        perror("Out file");
    }
    else {
        std::cout << "Enter a text :";
        std::getline(std::cin, inputText);
        outFile << inputText << std::endl;

    }
    outFile.close();

}

void copyFile() {
    std::string Destination;
    std::string Origin;
    std::string temp;
    char st;
    std::cout << "Enter Origin file Name and address (use '\\\\' ):";
    std::cin >> Origin;
    std::fstream imageFile(Origin, std::ios::in | std::ios::binary);
    std::cout << "where do you want to copy the file (use '\\\\' ):";
    std::cin >> Destination;
    std::fstream CopyImageFile(Destination, std::ios::out | std::ios::binary);
    if (imageFile && CopyImageFile) {
        perror("Image File");
        while (imageFile.get(st)) {
            CopyImageFile << st;
        }
    }
    else {
        perror("Image File");
    }


}
int main()
{

   //  iomanipBool();
  //  iomanipIntegers();
   // iomanipFloat();
   // WidthFillAlighn();
    //  readFromFile();
   //  readStory();

     //writeToFiles();
     writeToFile2();
     copyFile();
}