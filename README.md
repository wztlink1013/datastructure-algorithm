## Content
- 数据结构 [./src/com/wztlink1013/datastructure](./src/com/wztlink1013/datastructure)
- 算法分析与设计 [./src/com/wztlink1013/algorithm](./src/com/wztlink1013/algorithm)
- 编程刷题 [./src/com/wztlink1013/problems](./src/com/wztlink1013/problems)

## About
个人博客：[www.wztlink1013.com](https://www.wztlink1013.com/)

- [www.wztlink1013.com/blog/categories/Algorithm/](https://www.wztlink1013.com/blog/categories/Algorithm/)
- [www.wztlink1013.com/blog/categories/DataStructure/](https://www.wztlink1013.com/blog/categories/DataStructure/)

## Leetcode editor
> 记录LeetCode插件配置

- 勾选 Custom Template 和 Plugin Update
- TempFilePath
  > `D:\project-java\datastructure-algorithm\src\com\wztlink1013\problems`
- CodeFileName
  > `P${question.frontendQuestionId}$!velocityTool.camelCaseName(${question.titleSlug})`
- CodeTemplate

    ```
    package com.wztlink1013.problems.leetcode.editor.cn;

    ${question.content}
    public class P${question.frontendQuestionId}$!velocityTool.camelCaseName(${question.titleSlug}){
        public static void main(String[] args) {
            Solution solution = new P${question.frontendQuestionId}$!velocityTool.camelCaseName(${question.titleSlug})().new Solution();

        }

    ${question.code}
    }
    ```
## .vscode folder
#### launch.json
```json
{
    "version": "0.2.0",
    "configurations": [{
        "name": "(gdb) Launch", 
        "type": "cppdbg", 
        "request": "launch", 
        "program": "${fileDirname}/${fileBasenameNoExtension}.exe", 
        "args": [], 
        "stopAtEntry": false, 
        "cwd": "${workspaceFolder}", 
        "environment": [], 
        "externalConsole": true, 
        "internalConsoleOptions": "neverOpen", 
        "MIMode": "gdb", 
        "miDebuggerPath": "gdb.exe", 
        "setupCommands": [
            { 
                "description": "Enable pretty-printing for gdb",
                "text": "-enable-pretty-printing",
                "ignoreFailures": false
            }
        ],
        "preLaunchTask": "Compile" 
    }]
}
```
#### settings.json
```json
{
    "files.defaultLanguage": "c", 
    "editor.formatOnType": true,  
    "editor.suggest.snippetsPreventQuickSuggestions": false, 
    "editor.acceptSuggestionOnEnter": "off", 
    "code-runner.runInTerminal": true, 
    "code-runner.executorMap": {
        "c": "gcc '$fileName' -o '$fileNameWithoutExt.exe' -Wall -O2 -m64 -lm -static-libgcc -std=c11 -fexec-charset=GBK && &'./$fileNameWithoutExt.exe'",
        "cpp": "g++ '$fileName' -o '$fileNameWithoutExt.exe' -Wall -O2 -m64 -static-libgcc -std=c++14 -fexec-charset=GBK && &'./$fileNameWithoutExt.exe'"
    }, 
    "code-runner.saveFileBeforeRun": true, 
    "code-runner.preserveFocus": true,     
    "code-runner.clearPreviousOutput": false, 
    "code-runner.ignoreSelection": true,   
    "code-runner.fileDirectoryAsCwd": true, 

    "C_Cpp.clang_format_sortIncludes": true
}
```
#### tasks.json
```json
{
    "version": "2.0.0",
    "tasks": [{
        "label": "Compile", 
        "command": "gcc",   
        "args": [
            "${file}",
            "-o",    
            "${fileDirname}/${fileBasenameNoExtension}.exe",
            "-g",    
            "-m64", 
            "-Wall", 
            "-static-libgcc",     
            "-fexec-charset=GBK", 
            
        ], 
        "type": "process", 
        "group": {
            "kind": "build",
            "isDefault": true 
        },
        "presentation": {
            "echo": true,
            "reveal": "always", 
            "focus": false,     
            "panel": "shared"   
        },
        "problemMatcher":"$gcc" 
        
    }]
}
```