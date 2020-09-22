#include<cstdlib>
#include<iostream>
#include<string>
#include<fstream>

using namespace std;

char* Encrypter(const char*, const char*);
char* Decrypter(const char*, const char*);
void menu();
void Encrypt();
void Decrypt();

int main(void)
{
	menu();

	system("PAUSE");
	return 0;
}

// Allows the user choose whether they want to encrypt or decrypt a file.
void menu()
{
	char select;
	cout << "A. Create a file with an encrypted message." << endl;
	cout << "B. Read an encrypted text file." << endl;
	cout << "X. Exit the program." << endl;

	cin >> select;

	//Switch case to register user input
	do
	{
		switch (select)
		{
		case 'A':
		case 'a':
			Encrypt();
			break;

		case 'B':
		case 'b':
			Decrypt();
			break;

		case 'X':
		case 'x':
			exit(0);


		default:
			cout << "Please select one of the above choices.";
		}
	} while (select <= 0 || select > 3);
	

}

//Reads the user given key and shows the encrypted message.
void Encrypt()
{
	string word;
	string xorKey;

	//Reads user inputted word
	cout << "Enter a word to encrypt: ";
	cin >> word;

	//Reads user inputted key
	cout << "Please enter a key: ";
	cin >> xorKey;

	//Runs the Encrypter method with the word and key as parameters
	char* encrypt = Encrypter(word.c_str(), xorKey.c_str());
	cout << endl << "Encrypted String: " << encrypt << endl;
	menu();

}


//Reads the user key and words from a text file and displays the decrypted message.
void Decrypt()
{
	string xorKey;

	//Reads user inputted key
	cout << "Please enter a key: ";
	cin >> xorKey;

	//Reads a preset text file
	ifstream infile;
	infile.open("test.txt", ios::binary);
	string encrypt, write;

	//Reads the file line by line
	while (getline(infile, write))
	{
		encrypt = write;
	}
	infile.close();

	//Runs the Decrypter method with the word and key as parameters
	char* decrypt = Decrypter(encrypt.c_str(), xorKey.c_str());
	cout << "Decrypted String: " << decrypt << endl;
	menu();
}

//Writes the encrypted message to file
void WriteFile(string text)
{
	string filename;
	
	ofstream file;
	file.open("test.txt", ios::binary);
	file << text << endl;
	file.close();
}

//Encrypts the message using the given word and key
char * Encrypter(const char* inpString, const char* key)
{
	//Creates a char array based on the length of the string
	char* output = new char[strlen(inpString) + 1];
	memset(output, (int)'\0', strlen(inpString) + 1);

	int len = strlen(inpString);
	int keyLen = strlen(key);
	int x = 0;

	//For loop to set the encryption based on the string length
	for (int i = 0; i < len; i++)
	{
		
		output[i] = inpString[i] ^ key[x];
		x++;

		//Check if x is equal to or greater than the key length, if so, set it to 0
		if (x >= keyLen)
		{
			x = 0;
		}
	}

	WriteFile(output);
	return output;
}

//Decrypts the message using the given word and key
char * Decrypter(const char* inpString, const char* key)
{
	//Creates a char array based on the length of the string
	char* output = new char[strlen(inpString) + 1];
	memset(output, (int)'\0', strlen(inpString) + 1);

	int len = strlen(inpString);
	int keyLen = strlen(key);
	int x = 0;

	//For loop to set the decryption based on the string length
	for (int i = 0; i < len; i++)
	{

		output[i] = inpString[i] ^ key[x];
		x++;

		//Check if x is equal to or greater than the key length, if so, set it to 0
		if (x >= keyLen)
		{
			x = 0;
		}

	}

	return output;
}

