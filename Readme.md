1 Setting c++

Fix warning: range-based for loop is a C++11 extension [-Wc++11-extensions]
for (const string &word : msg)

Settings will open up.

Search `code-runner: Executor Map`

Find code-runner: Executor Map and click on the edit in settings.json.

Find the cpp and add -std=c++17 after g++

From
"cpp": "cd $dir && g++ $fileName -o $fileNameWithoutExt && $dir$fileNameWithoutExt"
To
"cpp": "cd $dir && g++ -std=c++17 $fileName -o $fileNameWithoutExt && $dir$fileNameWithoutExt"

Document install c++ on mac using clang

https://code.visualstudio.com/docs/cpp/config-clang-mac#_run-helloworldcpp
