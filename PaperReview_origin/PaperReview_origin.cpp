#define _CRT_SECURE_NO_WARNINGS // 忽略 fopen 的安全性警告

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>

// 定义最大文本长度
#define MAX_TEXT_LENGTH 100000

// 计算两个字符串的相似度
double CalculateSimilarity(const char* original, const char* copied) 
{
    int OriginalLen = strlen(original);
    int CopiedLen = strlen(copied);

    // 创建动态规划数组
    int** dp = (int**)malloc((OriginalLen + 1) * sizeof(int*));
    for (int i = 0; i <= OriginalLen; i++)
    {
        dp[i] = (int*)malloc((CopiedLen + 1) * sizeof(int));
    }

    // 动态规划
    for (int i = 0; i <= OriginalLen; i++)
    {
        for (int j = 0; j <= CopiedLen; j++)
        {
            if (i == 0 || j == 0) // 初始化第一行和第一列
                dp[i][j] = 0;
            else if (original[i - 1] == copied[j - 1])
                dp[i][j] = dp[i - 1][j - 1] + 1;
            else
                dp[i][j] = (dp[i - 1][j] > dp[i][j - 1]) ? dp[i - 1][j] : dp[i][j - 1];
        }
    }

    // 计算相似度
    double similarity = (double)dp[OriginalLen][CopiedLen] / OriginalLen;

    // 释放动态规划数组
    for (int i = 0; i <= OriginalLen; i++)
    {
        free(dp[i]);
    }
    free(dp);

    return similarity;
}

int main(int argc, char* argv[]) 
{
    //检查命令行参数
    if (argc != 4) 
    {
        printf("命令行参数错误\n命令行格式: %s <原文文件> <抄袭版文件> <答案文件>\n当前输入：", argv[0]);
        for (int i = 0; i < argc; i++)
            printf("%s\n", argv[i]);
        printf("共计%d个参数\n\n", argc);
        return 1;
    }

    // 打开原文文件
    FILE* OriginalFile;
    if (fopen_s(&OriginalFile, argv[1], "r") != 0) 
    {
        printf("无法打开原文文件\n");
        return 1;
    }

    // 打开抄袭版文件
    FILE* CopiedFile;
    if (fopen_s(&CopiedFile, argv[2], "r") != 0) 
    {
        printf("无法打开抄袭版文件\n");
        fclose(OriginalFile);
        return 1;
    }

    // 读取原文和抄袭版文本
    char OriginalText[MAX_TEXT_LENGTH];
    char CopiedText[MAX_TEXT_LENGTH];

    fgets(OriginalText, MAX_TEXT_LENGTH, OriginalFile);
    fgets(CopiedText, MAX_TEXT_LENGTH, CopiedFile);

    // 计算相似度
    double similarity = CalculateSimilarity(OriginalText, CopiedText);

    // 打开答案文件并写入相似度
    FILE* AnswerFile;
    if (fopen_s(&AnswerFile, argv[3], "w") != 0) 
    {
        printf("无法打开答案文件\n");
        fclose(OriginalFile);
        fclose(CopiedFile);
        return 1;
    }

    fprintf(AnswerFile, "重复率：%.2lf%%\n", similarity * 100);

    // 关闭所有文件
    fclose(OriginalFile);
    fclose(CopiedFile);
    fclose(AnswerFile);

    printf("重复率计算完成，结果已写入 %s\n", argv[3]);

    return 0;
}


