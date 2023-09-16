#define _CRT_SECURE_NO_WARNINGS // 忽略 fopen_s 的安全性警告

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>

// 定义最大文本长度
#define MAX_TEXT_LENGTH 100000

// 计算两个字符串的相似度
double calculateSimilarity(const char* original, const char* copied) 
{
    int original_len = strlen(original);
    int copied_len = strlen(copied);

    // 创建动态规划数组
    int** dp = (int**)malloc((original_len + 1) * sizeof(int*));
    for (int i = 0; i <= original_len; i++) 
    {
        dp[i] = (int*)malloc((copied_len + 1) * sizeof(int));
    }

    // 初始化第一行和第一列
    for (int i = 0; i <= original_len; i++) 
    {
        for (int j = 0; j <= copied_len; j++) 
        {
            if (i == 0 || j == 0)
                dp[i][j] = 0;
            else if (original[i - 1] == copied[j - 1])
                dp[i][j] = dp[i - 1][j - 1] + 1;
            else
                dp[i][j] = (dp[i - 1][j] > dp[i][j - 1]) ? dp[i - 1][j] : dp[i][j - 1];
        }
    }

    // 计算相似度
    double similarity = (double)dp[original_len][copied_len] / original_len;

    // 释放动态规划数组
    for (int i = 0; i <= original_len; i++) 
    {
        free(dp[i]);
    }
    free(dp);

    return similarity;
}

int main(int argc, char* argv[]) 
{
    //printf("%d\n", argc);
    //printf("%s\n", argv[0]);
    //printf("%s\n", argv[1]);
    //printf("%s\n", argv[2]);
    //printf("%s\n", argv[3]);
    //printf("%s\n", argv[4]);


    //检查命令行参数
    if (argc != 4) 
    {
        printf("用法: %s <原文文件> <抄袭版文件> <答案文件>\n", argv[0]);
        return 1;
    }

    // 打开原文文件
    FILE* original_file;
    if (fopen_s(&original_file, argv[1], "r") != 0) 
    {
        printf("无法打开原文文件\n");
        return 1;
    }

    // 打开抄袭版文件
    FILE* copied_file;
    if (fopen_s(&copied_file, argv[2], "r") != 0) 
    {
        printf("无法打开抄袭版文件\n");
        fclose(original_file);
        return 1;
    }

    // 读取原文和抄袭版文本
    char original_text[MAX_TEXT_LENGTH];
    char copied_text[MAX_TEXT_LENGTH];

    fgets(original_text, MAX_TEXT_LENGTH, original_file);
    fgets(copied_text, MAX_TEXT_LENGTH, copied_file);

    // 计算相似度
    double similarity = calculateSimilarity(original_text, copied_text);

    // 打开答案文件并写入相似度
    FILE* answer_file;
    if (fopen_s(&answer_file, argv[3], "w") != 0) 
    {
        printf("无法打开答案文件\n");
        fclose(original_file);
        fclose(copied_file);
        return 1;
    }

    fprintf(answer_file, "重复率：%.2lf%%\n", similarity * 100);

    // 关闭所有文件
    fclose(original_file);
    fclose(copied_file);
    fclose(answer_file);

    printf("重复率计算完成，结果已写入 %s\n", argv[3]);
    printf("相似度 %f\n", similarity);

    return 0;
}


