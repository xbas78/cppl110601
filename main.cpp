/*------------------------------------------------------------------------------
    Задача (11.6.) 1. Реализация шифра Цезаря
--------------------------------------------------------------------------------
  Что нужно сделать
  В древности для шифрования сообщений использовался такой способ: все буквы в
сообщении сдвигались на одно и то же число позиций в алфавите. Число позиций
могло быть как положительным, так и отрицательным и являлось параметром шифра.
Если для сдвига на данное число позиций алфавита не хватает, то он
зацикливается, то есть буква с номером 27 — это снова буква «a», буква с номером
28 — это «b» и так далее.
  Например, слово abracadabra при сдвиге на 10 позиций превратится в
klbkmknklbk. Этот простейший шифр называется шифром Цезаря. Регистр букв
(заглавные и строчные) менять не нужно. Напишите функцию encrypt_caesar от
строки и числа, которая возвращает исходную строку, зашифрованную шифром Цезаря
с параметром, равным данному числу. Также напишите функцию decrypt_caesar,
выполняющую обратное преобразование. Считаем, что входные строки состоят лишь
из английских букв; если там содержатся и другие символы, то их надо
игнорировать.

  Пример 1
The quick brown fox jumps over the lazy dog

  Результат:
Ymj vznhp gwtbs ktc ozrux tajw ymj qfed itl

  Пример 2
  Lorem ipsum dolor sit amet consectetur adipiscing elit sed do eiusmod tempor
incididunt ut labore et dolore magna aliqua Ut enim ad minim veniam quis
nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequat
Duis aute irure dolor in reprehenderit in voluptate velit esse cillum dolore eu
fugiat nulla pariatur Excepteur sint occaecat cupidatat non proident sunt in
culpa qui officia deserunt mollit anim id est laborum

  Результат:
  Knqdl hortl cnknq rhs zlds bnmrdbsdstq zchohrbhmf dkhs rdc cn dhtrlnc sdlonq
hmbhchctms ts kzanqd ds cnknqd lzfmz zkhptz Ts dmhl zc lhmhl udmhzl pthr
mnrsqtc dwdqbhszshnm tkkzlbn kzanqhr mhrh ts zkhptho dw dz bnllncn bnmrdptzs
Cthr ztsd hqtqd cnknq hm qdoqdgdmcdqhs hm unktoszsd udkhs drrd bhkktl cnknqd
dt etfhzs mtkkz ozqhzstq Dwbdosdtq rhms nbbzdbzs btohczszs mnm oqnhcdms rtms
hm btkoz pth neehbhz cdrdqtms lnkkhs zmhl hc drs kzanqtl

  Советы и рекомендации
Уже имея функцию encrypt_caesar, функцию decrypt_caesar можно реализовать в
одну строчку.

  Что оценивается
Корректность работы программы по созданию зашифрованной версии слова или текста.

  Как отправить задание на проверку:
Прислать ссылку на repl.it или файл *.срр с решением. Также вы можете создать
открытый репозиторий в GitHub с содержимым проекта.
------------------------------------------------------------------------------*/
#include <iostream>

constexpr int NUM_SYMBOLS = 'z' - 'a' + 1;

// String encryption function
std::string encrypt_caesar(std::string str, int key) {

  unsigned short len = str.length();
  key %= NUM_SYMBOLS;

  for (unsigned short i = 0; i < len; i++) {
    unsigned short asciiPos = (short) str[i];
    unsigned short newAsciiPos = asciiPos;

    if (asciiPos >= 'a' && asciiPos <= 'z') {
      newAsciiPos = asciiPos + key;
      if (newAsciiPos > 'z') newAsciiPos -= NUM_SYMBOLS;
      if (newAsciiPos < 'a') newAsciiPos += NUM_SYMBOLS;
    } else {
      if (asciiPos >= 'A' && asciiPos <= 'Z') {
        newAsciiPos = asciiPos + key;
        if (newAsciiPos > 'Z') newAsciiPos -= NUM_SYMBOLS;
        if (newAsciiPos < 'A') newAsciiPos += NUM_SYMBOLS;
      }
    }

    str[i] = (char) newAsciiPos;
  }

  return str;
}

// String decryption function
std::string decrypt_caesar(std::string str, int key) {
  return encrypt_caesar(str, -key);
}

int main() {

  // String input
  std::string str;
  int key;
  std::cout << "Input your text to encrypt: ";
  std::getline (std::cin, str);
  std::cout << "Input the key: ";
  std::cin >> key;

  // Result output
  str = encrypt_caesar(str, key);
  std::cout << std::endl << "Encrypted text: " << str << std::endl;
  str = decrypt_caesar(str, key);
  std::cout << "Decrypted text: " << str << std::endl;

  return 0;
}