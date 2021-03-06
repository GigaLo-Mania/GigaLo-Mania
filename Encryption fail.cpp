/*
Name: Rodney Richards 
ID: 10131258

Description: Encryption 
*/

#include <iostream>
#include <string>
#include <cctype>

using std::islower;
using std::isupper;
using std::string;

class CeaserEncrypter
{
private:
	
	const string alpha_lower = "abcdefghijklmnopqrstuvwxyz";
	const string alpha_upper = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    string text, encryption;
    int shift;
public:
    CeaserEncrypter() {
        text = encryption = "";
        shift = 0;
    }
    CeaserEncrypter(int p_shift) {
        text = encryption = "";
        shift = p_shift;
    }
    void set_shift_key(int new_key) {
        shift = new_key;
    }
    void encrypt() {
        encryption = "";
        for (char c : text)
            encryption += shift_char(c, true);
    }
    void decrypt() {
        text = "";
        for (char c : encryption)
            text += shift_char(c, false);
    }
    string encrypt_text(string text) {
        this->text = text;
        encrypt();
        return encryption;
    }
    string decrypt_text(string encryption) {
        this->encryption = encryption;
        decrypt();
        return text;
    }
    string get_text() { return text; }
    string get_encryption() { return encryption; }

private: 

	char shift_char(char c, bool encrypt)
	{
		int original_index, shift_index;

		const string* alpha_set;

		if (islower(c))
		{
			original_index = get_alpha_index(c, false);
			alpha_set = &alpha_lower;
		}
		
		else if (isupper(c))
		{
			original_index = get_alpha_index(c, true);
			alpha_set = &alpha_upper;
		}
		
		else
			return c;

		int new_index;
		int size;

		if (encrypt == true)
		{
			new_index = original_index + shift;
			size = alpha_set->size();
		}

		
		else
		{
			new_index = original_index - shift;
			size = alpha_set->size();
		}

		 
		if (new_index >= size)
			shift_index = (new_index - alpha_set->size()) % alpha_set->size();
		else if (new_index < 0)
			shift_index = (new_index + alpha_set->size()) % alpha_set->size();
		else
			shift_index = new_index % alpha_set->size();
  
		return (*(alpha_set))[shift_index];

	}

	int get_alpha_index(char c, bool shift)
	{
		
		const string* alpha_set;

		if (shift == true)
			alpha_set = &alpha_upper;
		else
			alpha_set = &alpha_lower;

		
		for (int i = 0; i < alpha_set->size(); i++)
		{
			
			if (c == (*(alpha_set))[i])
				return i;
		}

		return -1;
	}
};

int main() {
	CeaserEncrypter ce(5);
	string encr = ce.encrypt_text("Attack at Dawn");
	std::cout << encr << std::endl;
	ce.decrypt();
	std::cout << ce.get_text() << std::endl;

	ce.set_shift_key(7);
	ce.encrypt_text("CeaserEncrypter ce (5)");
	std::cout << ce.get_encryption() << std::endl;
	std::cout << ce.decrypt_text(ce.get_encryption()) << std::endl;
}