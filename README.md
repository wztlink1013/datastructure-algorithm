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
