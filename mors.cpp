#include <iostream>
#include <string>
#include <windows.h>
#include <chrono>


void bip(std::string morse)
{
	
    unsigned int freq = 512, dash = 500, dot = 200; // Recommended --> dash time x3 then dot

	for (int i = 0; i < morse.length(); i++)
	{

		if (morse.at(i) == '.')
			Beep(freq, dot);
		else if(morse.at(i) == '-')
			Beep(freq, dash);

		Sleep(1000);
		
	}

}
std::string morse(std::string userInput) {
	std::string morseCode[58];
	morseCode[0] = "-.-.--"; //!
	morseCode[1] = ".-..-."; //"
	morseCode[2] = ""; //#
	morseCode[3] = ""; //$
	morseCode[4] = ""; //%
	morseCode[5] = ""; //&
	morseCode[6] = ".---."; //'
	morseCode[7] = ""; //(
	morseCode[8] = ""; //)
	morseCode[9] = ""; //*
	morseCode[10] = ".-.-."; //+
	morseCode[11] = "--..--"; //,
	morseCode[12] = "-....-"; //-
	morseCode[13] = ".-.-.-"; //.
	morseCode[14] = "-..-."; // /
	morseCode[15] = "-----"; //0
	morseCode[16] = ".----"; //1
	morseCode[17] = "..---"; //2
	morseCode[18] = "...--"; //3
	morseCode[19] = "....-"; //4
	morseCode[20] = "......"; //5
	morseCode[21] = "-...."; //6
	morseCode[22] = "--..."; //7
	morseCode[23] = "---.."; //8
	morseCode[24] = "----."; //9
	morseCode[25] = "---..."; //:
	morseCode[26] = "-.-.-."; //;
	morseCode[27] = ""; //<
	morseCode[28] = "-...-"; //=
	morseCode[29] = ""; //>
	morseCode[30] = "..--.."; //?
	morseCode[31] = ".--.-."; //@
	morseCode[32] = ".-"; //A
	morseCode[33] = "-..."; //B
	morseCode[34] = "-.-."; //C
	morseCode[35] = "-.."; //D
	morseCode[36] = "."; //E
	morseCode[37] = "..-."; //F
	morseCode[38] = "--."; //G
	morseCode[39] = "...."; //H
	morseCode[40] = ".."; //I
	morseCode[41] = ".---"; //J
	morseCode[42] = "-.-"; //K
	morseCode[43] = ".-.."; //L
	morseCode[44] = "--"; //M
	morseCode[45] = "-."; //N
	morseCode[46] = "---"; //O
	morseCode[47] = ".--."; //P
	morseCode[48] = "--.-"; //Q
	morseCode[49] = ".-."; //R
	morseCode[50] = "..."; //S
	morseCode[51] = "-"; //T
	morseCode[52] = "..-"; //U
	morseCode[53] = "...-"; //V
	morseCode[54] = ".--"; //W
	morseCode[55] = "-..-"; //X
	morseCode[56] = "-.--"; //Y
	morseCode[57] = "--.."; //Z
	std::string translate = "";
	std::string capUserInput;
	for (std::string::iterator itr = userInput.begin(); itr != userInput.end(); ++itr)
	{
		capUserInput += toupper(*itr);
	}

	for (int i = 0; i < capUserInput.length(); i++) {

		int c = capUserInput[i] - 33;
		if (c >= 0 && c <= 58)
			translate += morseCode[c];
	}
	

	return translate;
}

int main() {
	int operation;
	std::string userInput;
		while (true) {
			std::cout << "Choose an operation:" << std::endl;
			std::cout << "Select 1 to translate morse code" << std::endl;
			std::cout << "Select 2 to translate morse code with sound" << std::endl;
			std::cout << "Select 0 to end the programm" << std::endl;
			std::cin >> operation;
			std::cin.get();

			std::cout << operation << std::endl;
			
			
			if (operation == 1)
			{
				std::cout << "Input a message to translate into Morse code: " << std::endl;
				std::getline(std::cin, userInput);
				
				std::string morseEq = morse(userInput);
				std::cout << morseEq << std::endl;
				
			}
			else if (operation == 2) {
				std::cout << "Input a message to translate into Morse code: " << std::endl;
				std::getline(std::cin, userInput);

				std::string morseEq = morse(userInput);
				std::cout << morseEq << std::endl;
				bip(morseEq);

			}
			else if (operation == 0)
			{
				break;
			}

			

		}

	
	

	return 0;
}
