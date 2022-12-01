#include <string>
#include <iostream>
#include <cassert>
#include <algorithm>
using namespace std;

string clear_slash(string const &path_of_file, string const &d_slash = "/\\")
{
    size_t index_of_slash = path_of_file.find_last_of(d_slash);
    string file_name = path_of_file.substr(index_of_slash + 1);
    return file_name;
}

string extension_removal(string const &name_of_file)
{
    size_t index_of_period = name_of_file.find_last_of('.');
    string file_without_extension = name_of_file.substr(0, index_of_period);
    return file_without_extension;
}
string removeSeparators(string file_name)
{
    string temp = ""; // initializing a temporary string

    for (int i = 0; i < file_name.size(); ++i)
    {
        if ((file_name[i] >= 'a' && file_name[i] <= 'z') || (file_name[i] >= 'A' && file_name[i] <= 'Z')) // initializing condition
        {
            temp = temp + file_name[i]; // passing characters that match condition to temp string from initialized string
        }
    }
    file_name = temp;
    return file_name;
}

string removeWords(string file_name)
{
    string skipWords[] = {"tests", "test", "Tests", "Test", "spec", "Spec", "steps", "step"};
    for (string skipWord : skipWords)
    {
        size_t pos = file_name.find(skipWord, 0);
        if (pos != string::npos)
            file_name.erase(pos, skipWord.length());
    }
    return file_name;
}

string getIndex(string file_path, string file_name)
{
    int index[2];
    size_t pos = file_path.find(file_name, 0);
    index[0] = pos;
    index[1] = pos + file_name.length();
    return to_string(index[0]) + " " + to_string(index[1]);
}

string fileName(string file_Path)
{
    string file_address = removeWords(removeSeparators(extension_removal(clear_slash(file_Path))));
    return getIndex(file_Path, file_address);
}

void test_Cases()
{
    assert(fileName("src/Hiker_spec.re") == "4 9");
    assert(fileName("test/hiker_test.exs") == "5 10");
    assert(fileName("wibble/test/hiker_spec.rb") == "12 17");
    assert(fileName("hiker_steps.rb") == "0 5");
    assert(fileName("hiker_spec.rb") == "0 5");
    assert(fileName("test_hiker.rb") == "5 10");
    assert(fileName("test_hiker.py") == "5 10");
    assert(fileName("test_hiker.sh") == "5 10");
    assert(fileName("tests_hiker.sh") == "6 11");
    assert(fileName("test_hiker.coffee") == "5 10");
    assert(fileName("hiker_spec.coffee") == "0 5");
    assert(fileName("hikerTest.chpl") == "0 5");
    assert(fileName("hiker.tests.c") == "0 5");
    assert(fileName("hiker_tests.c") == "0 5");
    assert(fileName("hiker_test.c") == "0 5");
    assert(fileName("hiker_Test.c") == "0 5");
    assert(fileName("HikerTests.cpp") == "0 5");
    assert(fileName("hikerTests.cpp") == "0 5");
    assert(fileName("HikerTest.cs") == "0 5");
    assert(fileName("HikerTest.java") == "0 5");
    assert(fileName("DiamondTest.kt") == "0 7");
    assert(fileName("HikerTest.php") == "0 5");
    assert(fileName("hikerTest.js") == "0 5");
    assert(fileName("hiker-test.js") == "0 5");
    assert(fileName("hiker-spec.js") == "0 5");
    assert(fileName("hiker.test.js") == "0 5");
    assert(fileName("hiker.tests.ts") == "0 5");
    assert(fileName("hiker_tests.erl") == "0 5");
    assert(fileName("hiker_test.clj") == "0 5");
    assert(fileName("fizzBuzz_test.d") == "0 8");
    assert(fileName("hiker_test.go") == "0 5");
    assert(fileName("hiker.tests.R") == "0 5");
    assert(fileName("hikertests.swift") == "0 5");
    assert(fileName("HikerSpec.groovy") == "0 5");
    assert(fileName("hikerSpec.feature") == "0 5");
    assert(fileName("hiker.feature") == "0 5");
    assert(fileName("hiker.fun") == "0 5");
    assert(fileName("hiker.t") == "0 5");
    assert(fileName("hiker.plt") == "0 5");
    assert(fileName("hiker") == "0 5");
    std::cout << "All test Cases Passed" << std::endl;
}

int main()
{
    test_Cases();
    return 0;
}
