#pragma warning(disable:4996)
#include<iostream>
#include<string>
#include<fstream>
#include<cstdlib>
#include<time.h>
#include<windows.h>
#include<malloc.h>
#include<stdio.h>
#include<chrono>
#include<thread>
#include<iomanip>
#include<vector>
#include<cstdio>
#define STR_LEN 50
#define FILEPATH1 "1.dat"
#define FILEPATH2 "2.dat"
using namespace std;

//火车、座位数据信息的结构体
struct train {
    char number[20];
    char begin_station[20];
    char mid_station[20];
    char terminal[20];
    char begin_time[20];
    char mid_time[20];
    char end_time[20];
    char first_class_one[20];
    char second_class_one[20];
    char business_class_one[20];
    char first_class_two[20];
    char second_class_two[20];
    char business_class_two[20];
    char first_class_fee_one[20];
    char second_class_fee_one[20];
    char business_class_fee_one[20];
    char first_class_fee_two[20];
    char second_class_fee_two[20];
    char business_class_fee_two[20];
};

//乘客信息的结构体
struct passenger
{
    char name[20];
    char ID_number[20];
    char train_number[20];
    char seat_type[20];
    char begin[20];
    char end[20];
};

//链表节点类型
struct Node1 {
    struct train data; //链表节点存储的数据
    struct Node1* pNext;//保存下一个节点地址
};

struct Node2 {
    struct passenger data; //链表节点存储的数据
    struct Node2* rNext;//保存下一个节点地址
};

//1.创建一个链表节点(对列车数组）
struct Node1* createNode_train(struct train* pData)
{
    struct Node1* pNew = (Node1*)malloc(sizeof(struct Node1));
    if (NULL == pNew) return NULL;
    pNew->pNext = NULL;
    strcpy(pNew->data.number, pData->number);
    strcpy(pNew->data.begin_station, pData->begin_station);
    strcpy(pNew->data.mid_station, pData->mid_station);
    strcpy(pNew->data.terminal, pData->terminal);
    strcpy(pNew->data.begin_time, pData->begin_time);
    strcpy(pNew->data.mid_time, pData->mid_time);
    strcpy(pNew->data.end_time, pData->end_time);
    strcpy(pNew->data.first_class_one, pData->first_class_one);
    strcpy(pNew->data.second_class_one, pData->second_class_one);
    strcpy(pNew->data.business_class_one, pData->business_class_one);
    strcpy(pNew->data.first_class_two, pData->first_class_two);
    strcpy(pNew->data.second_class_two, pData->second_class_two);
    strcpy(pNew->data.business_class_two, pData->business_class_two);
    strcpy(pNew->data.first_class_fee_one, pData->first_class_fee_one);
    strcpy(pNew->data.second_class_fee_one, pData->second_class_fee_one);
    strcpy(pNew->data.business_class_fee_one, pData->business_class_fee_one);
    strcpy(pNew->data.first_class_fee_two, pData->first_class_fee_two);
    strcpy(pNew->data.second_class_fee_two, pData->second_class_fee_two);
    strcpy(pNew->data.business_class_fee_two, pData->business_class_fee_two);
    return pNew;
}

//创建一个链表节点(对乘客数组）
struct Node2* createNode_passenger(struct passenger* rData)
{
    struct Node2* rNew = (Node2*)malloc(sizeof(struct Node2));
    if (NULL == rNew) return NULL;
    rNew->rNext = NULL;
    strcpy(rNew->data.name, rData->name);
    strcpy(rNew->data.ID_number, rData->ID_number);
    strcpy(rNew->data.train_number, rData->train_number);
    strcpy(rNew->data.seat_type, rData->seat_type);
    strcpy(rNew->data.begin, rData->begin);
    strcpy(rNew->data.end, rData->end);
    return rNew;
}

//2.添加一个链表节点到原链表末尾(对列车数组操作）
void appendNode_train(struct Node1** root, struct train* pData)
{
    if (root == NULL)
    {
        return;
    }
    if (*root == NULL)
    {
        *root = createNode_train(pData);
        return;
    }
    struct Node1* pTemp = *root;
    while (pTemp->pNext) pTemp = pTemp->pNext;//让ptemp指向链表最后一个节点
    pTemp->pNext = createNode_train(pData);//把新节点添加到ptemp后面
    pTemp->pNext->pNext = NULL;
}

//添加一个链表节点到原链表末尾(对乘客数组操作）
void appendNode_passenger(struct Node2** root, struct passenger* rData)
{
    if (root == NULL)
    {
        return;
    }
    if (*root == NULL)
    {
        *root = createNode_passenger(rData);
        return;
    }
    struct Node2* rTemp = *root;
    while (rTemp->rNext != NULL) rTemp = rTemp->rNext;//让ptemp指向链表最后一个节点
    rTemp->rNext = createNode_passenger(rData);//把新节点添加到ptemp后面
    rTemp->rNext->rNext = NULL;
}


//5.遍历列车信息的链表并输出
void travel_train(struct Node1* root)
{
    if (root == NULL)
    {
        return;
    }
    while (root)
    {
        cout << setiosflags(ios_base::left);
        cout << setw(11) << root->data.number;
        cout << setw(11) << root->data.begin_station;
        cout << setw(11) << root->data.mid_station;
        cout << setw(12) << root->data.terminal;
        cout << setw(14) << root->data.begin_time;
        cout << setw(15) << root->data.mid_time;
        cout << setw(15) << root->data.end_time;
        cout << endl;
        cout << setiosflags(ios_base::left);
        root = root->pNext;
    }
    cout << "----------------------------------------------------------------------------------------------\n";
    return;
}

//遍历座位数量的链表并输出
void travel_seat_num(struct Node1* root)
{
    if (root == NULL)
    {
        return;
    }
    while (root)
    {
        cout << setiosflags(ios_base::left);
        cout << setw(15) << root->data.number;
        cout << setw(17) << root->data.business_class_one;
        cout << setw(17) << root->data.first_class_one;
        cout << setw(19) << root->data.second_class_one;
        cout << setw(20) << root->data.business_class_two;
        cout << setw(20) << root->data.first_class_two;
        cout << setw(22) << root->data.second_class_two;
        cout << endl;
        cout << setiosflags(ios_base::left);
        root = root->pNext;
    }
    cout << "-----------------------------------------------------------------------------------------------------------\n";
    return;
}

//遍历座位信息的链表并输出
void travel_seat(struct Node1* root)
{
    if (root == NULL)
    {
        return;
    }
    while (root)
    {
        cout << setiosflags(ios_base::left);
        cout << setw(15) << root->data.number;
        cout << setw(17) << root->data.business_class_fee_one;
        cout << setw(17) << root->data.first_class_fee_one;
        cout << setw(19) << root->data.second_class_fee_one;
        cout << setw(20) << root->data.business_class_fee_two;
        cout << setw(20) << root->data.first_class_fee_two;
        cout << setw(22) << root->data.second_class_fee_two;
        cout << endl;
        cout << setiosflags(ios_base::left);
        root = root->pNext;
    }
    cout << "---------------------------------------------------------------------------------------------------------\n";
    return;
}

//遍历车票信息的链表并输出
void travel_tickets(struct Node2* current)
{
    if (current == NULL)
    {
        return;
    }
    while (current)
    {
        cout << setiosflags(ios_base::left);
        cout << setw(12) << current->data.name;
        cout << setw(12) << current->data.ID_number;
        cout << setw(13) << current->data.train_number;
        cout << setw(13) << current->data.seat_type;
        cout << " ";
        cout << setw(12) << current->data.begin;
        cout << setw(11) << current->data.end;
        cout << endl;
        cout << setiosflags(ios_base::left);
        current = current->rNext;
    }
    cout << "---------------------------------------------------------------------------------------------------------\n";
    return;
}

//6.返回root链表中第n个节点的地址
struct Node1* fineNodeByPos1(struct Node1* root, int n)
{
    if (n < 0) return NULL;
    if (root == NULL)return NULL;
    if (n == 0)return root;
    for (int i = 0; i < n; i++)
    {
        if (root == NULL) return NULL;
        root = root->pNext;
    }
    return root;
}

struct Node2* fineNodeByPos2(struct Node2* root, int n)
{
    if (n < 0) return NULL;
    if (root == NULL)return NULL;
    if (n == 0)return root;
    for (int i = 0; i < n; i++)
    {
        if (root == NULL) return NULL;
        root = root->rNext;
    }
    return root;
}


//7.删除root链表中第n个节点(n从0开始计算）
void del_Node1(struct Node1** root, int n)
{
    if (root == NULL)return;
    if (*root == NULL) return;
    if (n < 0) return;
    struct Node1* pDel = *root;
    struct Node1* pDelPret;
    if (n == 0)
    {
        *root = pDel->pNext;
        free(pDel);//释放内存
        return;
    }
    pDelPret = fineNodeByPos1(*root, n - 1);
    pDel = pDelPret->pNext;
    if (pDel == NULL) return;
    pDelPret->pNext = pDel->pNext;//pDel的前一个指针指向pDel的下一个节点（中间那个节点删掉）
    free(pDel);
    return;
}

void del_Node2(struct Node2** root, int n)
{
    if (root == NULL)return;
    if (*root == NULL) return;
    if (n < 0) return;
    struct Node2* pDel = *root;
    struct Node2* pDelPret;
    if (n == 0)
    {
        *root = pDel->rNext;
        free(pDel);//释放内存
        return;
    }
    pDelPret = fineNodeByPos2(*root, n - 1);
    pDel = pDelPret->rNext;
    if (pDel == NULL) return;
    pDelPret->rNext = pDel->rNext;//pDel的前一个指针指向pDel的下一个节点（中间那个节点删掉）
    free(pDel);
    return;
}

//8.删除整个链表
void deleteList1(struct Node1** root)
{
    while (1)
    {
        if (*root == NULL) break;
        del_Node1(root, 0);
    }
    return;
}

void deleteList2(struct Node2** root)
{
    while (1)
    {
        if (*root == NULL) break;
        del_Node2(root, 0);
    }
    return;
}

//9.按值查找函数
void findtrain(struct Node1* current)
{
    string checi;
    cout << "请输入要查找的车次：";
    cin >> checi;
    while (current != NULL && current->data.number != checi)
    {
        current = current->pNext;
    }
    if (current == NULL)
    {
        cout << "没有查找到对应车次！";
        return;
    }
    else
    {
        cout << "查找的车次信息是：";
        cout << endl;
        cout << "车次        始发站        途经        终点站        发车时间        途经时间        到站时间";
        cout << endl;
        cout << setiosflags(ios_base::left);
        cout << setw(13) << current->data.number;
        cout << setw(14) << current->data.begin_station;
        cout << setw(13) << current->data.mid_station;
        cout << setw(13) << current->data.terminal;
        cout << setw(15) << current->data.begin_time;
        cout << setw(17) << current->data.mid_time;
        cout << setw(17) << current->data.end_time;
        cout << setiosflags(ios_base::left);
        cout << endl;
    }
}

//按值查找函数
void findseat(struct Node1* current)
{
    string checi;
    cout << "请输入要查找的车次：";
    cin >> checi;
    while (current->data.number != checi && current != NULL)
    {
        current = current->pNext;
    }
    if (current == NULL)
    {
        cout << "没有查找到对应车次！";
    }
    else
    {
        cout << "查找的座位信息是：";
        cout << endl;
        cout << "车次    商务座价(始->中)   一等座价(始->中)   二等座价(始->中)   商务座价(中->终)   一等座价(中->终)   二等座价(中->终)";
        cout << endl;
        cout << setiosflags(ios_base::left);
        cout << setw(15) << current->data.number;
        cout << setw(17) << current->data.business_class_fee_one;
        cout << setw(17) << current->data.first_class_fee_one;
        cout << setw(19) << current->data.second_class_fee_one;
        cout << setw(20) << current->data.business_class_fee_two;
        cout << setw(20) << current->data.first_class_fee_two;
        cout << setw(22) << current->data.second_class_fee_two;
        cout << setiosflags(ios_base::left);
        cout << endl;
    }
}

//查找乘客车票信息的函数
void findpassenger(struct Node2* current)
{
    string sfz;
    cout << "请输入身份证号：";
    cin >> sfz;
    int flag = 0;
    while (current != NULL)
    {
        if (current->data.ID_number != sfz)
        {
            current = current->rNext;
        }
        else
        {
            flag += 1;
            if (flag == 1)
            {
                cout << "查找的座位信息如下：";
                cout << endl;
                cout << "姓名       身份证号       车次       座位类型       起点       终点";
                cout << endl;
                cout << setiosflags(ios_base::left);
                cout << setw(12) << current->data.name;
                cout << setw(12) << current->data.ID_number;
                cout << setw(13) << current->data.train_number;
                cout << setw(13) << current->data.seat_type;
                cout << " ";
                cout << setw(12) << current->data.begin;
                cout << setw(11) << current->data.end;
                cout << endl;
                cout << setiosflags(ios_base::left);
            }
            else
            {
                cout << setiosflags(ios_base::left);
                cout << setw(12) << current->data.name;
                cout << setw(12) << current->data.ID_number;
                cout << setw(13) << current->data.train_number;
                cout << setw(13) << current->data.seat_type;
                cout << " ";
                cout << setw(12) << current->data.begin;
                cout << setw(11) << current->data.end;
                cout << endl;
                cout << setiosflags(ios_base::left);
            }
            current = current->rNext;
        }
    }
    if (flag == 0)
    {
        cout << "未查找到该乘客的车票信息！";
        return;
    }
    else
    {
        return;
    }
}

//另一个按值查找函数
struct Node1* find_train_by_num(struct Node1* current)
{
    string checi;
    cout << "请输入要查找的车次：";
    cin >> checi;
    while (current != NULL && current->data.number != checi)
    {
        current = current->pNext;
    }
    if (current == NULL)
    {
        cout << "没有查找到对应车次！";
        return NULL;
    }
    else
    {
        return current;
    }
}

//字符串切片函数
void split(string s, string time[2])
{
    int c = 0;
    string separator = ":";
    auto func = [&](string& s, string& separator)
        {
            int t = 1, pre = 0;
            vector<string> res;
            while (t != -1)
            {
                t = s.find(separator, pre);
                if (t != -1)
                    res.push_back(s.substr(pre, t - pre));
                else
                    break;
                pre = t + separator.size();
            }
            if (pre < s.size())
                res.push_back(s.substr(pre));
            return res;
        };
    auto res = func(s, separator);
    for (auto i : res)
    {
        time[c] = i;
        c += 1;
    }
    return;
}

//按给定时间查找车次的函数
void find_train_by_time(struct Node1* current, string a, int style, string checi[20])
{
    string time[2];
    int i = 0;
    int m = 0;
    if (style == 1)
    {
        while (current != NULL)
        {
            split(current->data.begin_time, time);
            if (a == time[0])
            {
                checi[i] = current->data.number;
                i += 1;
            }
            current = current->pNext;
        }
        if (i == 0)
        {
            cout << "未查找到相关车次！";
            return;
        }
        else
        {
            cout << "查找的车次如下：";
            cout << endl;
            while (m < i)
            {
                cout << checi[m];
                cout << endl;
                m += 1;
            }
            return;
        }
    }
    else if (style == 2)
    {
        while (current != NULL)
        {
            split(current->data.mid_time, time);
            if (a == time[0])
            {
                checi[i] = current->data.number;
                i += 1;
            }
            current = current->pNext;
        }
        if (i == 0)
        {
            cout << "未查找到相关车次！";
            return;
        }
        else
        {
            cout << "查找的车次如下：";
            cout << endl;
            while (m < i)
            {
                cout << checi[m];
                cout << endl;
                m += 1;
            }
            return;
        }
    }
    else if (style == 3)
    {
        while (current != NULL)
        {
            split(current->data.end_time, time);
            if (a == time[0])
            {
                checi[i] = current->data.number;
                i += 1;
            }
            current = current->pNext;
        }
        if (i == 0)
        {
            cout << "未查找到相关车次！";
            return;
        }
        else
        {
            cout << "查找的车次如下：";
            cout << endl;
            while (m < i)
            {
                cout << checi[m];
                cout << endl;
                m += 1;
            }
            return;
        }
    }
    else
    {
        cout << "输入的时间类型不正确！";
        return;
    }
}

//给定参数的按值查找函数
struct Node1* find_train_by_num_given(struct Node1* current, string checi)
{
    while (current != NULL && current->data.number != checi)
    {
        current = current->pNext;
    }
    if (current == NULL)
    {
        cout << "没有查找到对应车次！";
        return NULL;
    }
    else
    {
        return current;
    }
}

//按照站点查找列车的函数
void find_train_by_station(struct Node1* current, string t[20], string begin, string end)
{
    int i = 0;
    string a, b, c;
    while (current != NULL)
    {
        a = current->data.begin_station;
        b = current->data.mid_station;
        c = current->data.terminal;
        if ((a == begin && b == end) or (a == begin && c == end) or (b == begin && c == end))
        {
            t[i] = current->data.number;
            i += 1;
        }
        current = current->pNext;
    }
    if (i == 0)
    {
        cout << "没有查找到相应车次！";
    }
    return;
}

//#显示所有列车的函数
void showAlltrains()
{
    FILE* fp = fopen(FILEPATH1, "rb");
    if (fp == NULL)
    {
        std::string folderPath = ".";
        std::string fileName = "1.dat";
        std::ofstream outputFile;
        outputFile.open(folderPath + "\\" + fileName);
        outputFile.close();
        fp = fopen(FILEPATH1, "rb");
    }
    //读取文件内容并存入链表
    struct Node1* pList = NULL;
    int r;
    struct train temp;//临时存储一列火车数据
    while (1)
    {
        r = fread(&temp, 1, sizeof(struct train), fp);
        if (r <= 0)//未读取到数据
        {
            break;
        }
        else//读取到了
        {
            appendNode_train(&pList, &temp);
        }
    }
    fclose(fp);
    //遍历链表并输出
    cout << "车次      始发站      途经      终点站      发车时间      途经时间      到站时间";
    cout << endl;
    travel_train(pList);
    //最后要删除整个链表
    deleteList1(&pList);
}

//#显示所有列车座位信息的函数
void showAllSeats_num()
{
    FILE* fp = fopen(FILEPATH1, "rb");
    if (fp == NULL)
    {
        std::string folderPath = ".";
        std::string fileName = "1.dat";
        std::ofstream outputFile;
        outputFile.open(folderPath + "\\" + fileName);
        outputFile.close();
        fp = fopen(FILEPATH1, "rb");
    }

    //读取文件内容并存入链表
    struct Node1* pList = NULL;
    int r;
    struct train temp;//临时存储一列火车数据
    while (1)
    {
        r = fread(&temp, 1, sizeof(struct train), fp);
        if (r <= 0)//未读取到数据
        {
            break;
        }
        else//读取到了
        {
            appendNode_train(&pList, &temp);
        }
    }
    fclose(fp);
    cout << "车次    商务座数(始->中)   一等座数(始->中)   二等座数(始->中)   商务座数(中->终)   一等座数(中->终)   二等座数(中->终)";
    cout << endl;
    //遍历链表并输出
    travel_seat_num(pList);
    //最后要删除整个链表
    deleteList1(&pList);
}

//显示所有列车所剩座位数量的函数
void showAllSeats()
{
    FILE* fp = fopen(FILEPATH1, "rb");
    if (fp == NULL)
    {
        std::string folderPath = ".";
        std::string fileName = "1.dat";
        std::ofstream outputFile;
        outputFile.open(folderPath + "\\" + fileName);
        outputFile.close();
        fp = fopen(FILEPATH1, "rb");
    }

    //读取文件内容并存入链表
    struct Node1* pList = NULL;
    int r;
    struct train temp;//临时存储一列火车数据
    while (1)
    {
        r = fread(&temp, 1, sizeof(struct train), fp);
        if (r <= 0)//未读取到数据
        {
            break;
        }
        else//读取到了
        {
            appendNode_train(&pList, &temp);
        }
    }
    fclose(fp);
    cout << "车次    商务座价(始->中)   一等座价(始->中)   二等座价(始->中)   商务座价(中->终)   一等座价(中->终)   二等座价(中->终)";
    cout << endl;
    //遍历链表并输出
    travel_seat(pList);
    //最后要删除整个链表
    deleteList1(&pList);
}


//显示所有车票信息的函数
void showAllTickets()
{
    FILE* fp = fopen(FILEPATH2, "rb");
    if (fp == NULL)
    {
        std::string folderPath = ".";
        std::string fileName = "2.dat";
        std::ofstream outputFile;
        outputFile.open(folderPath + "\\" + fileName);
        outputFile.close();
        fp = fopen(FILEPATH2, "rb");
    }
    //读取文件内容并存入链表
    struct Node2* rList = NULL;
    int r;
    struct passenger temp;//临时存储一列火车数据
    while (1)
    {
        r = fread(&temp, 1, sizeof(struct passenger), fp);
        if (r <= 0)//未读取到数据
        {
            break;
        }
        else//读取到了
        {
            appendNode_passenger(&rList, &temp);
        }
    }
    fclose(fp);
    //遍历链表并输出
    cout << "姓名       身份证号       车次       座位类型       起点       终点";
    cout << endl;
    travel_tickets(rList);
    //最后要删除整个链表
    deleteList2(&rList);
}

//#添加车次信息
void add_trains()
{
    FILE* fp = fopen(FILEPATH1, "rb");
    if (fp == NULL)
    {
        std::string folderPath = ".";
        std::string fileName = "1.dat";
        std::ofstream outputFile;
        outputFile.open(folderPath + "\\" + fileName);
        outputFile.close();
        fp = fopen(FILEPATH1, "rb");
    }
    //读取文件内容并存入链表
    struct Node1* pList = NULL;
    int r;
    struct train temp;//临时存储一列火车数据
    while (1)
    {
        r = fread(&temp, 1, sizeof(struct train), fp);
        if (r <= 0)//未读取到数据
        {
            break;
        }
        else//读取到了
        {
            appendNode_train(&pList, &temp);
        }
    }
    fclose(fp);

    cout << "请输入添加的车次：";
    cin >> temp.number;
    cout << "请输入添加的始发站：";
    cin >> temp.begin_station;
    cout << "请输入添加的途径：";
    cin >> temp.mid_station;
    cout << "请输入添加的终点站：";
    cin >> temp.terminal;
    cout << "请输入添加的发车时间：";
    cin >> temp.begin_time;
    cout << "请输入添加的途经时间：";
    cin >> temp.mid_time;
    cout << "请输入添加的到站时间：";
    cin >> temp.end_time;
    cout << "请输入添加的商务座数量(始->中)：";
    cin >> temp.business_class_one;
    cout << "请输入添加的商务座价格：";
    cin >> temp.business_class_fee_one;
    cout << "请输入添加的一等座数量(始->中)：";
    cin >> temp.first_class_one;
    cout << "请输入添加的一等座价格：";
    cin >> temp.first_class_fee_one;
    cout << "请输入添加的二等座数量(始->中)：";
    cin >> temp.second_class_one;
    cout << "请输入添加的二等座价格：";
    cin >> temp.second_class_fee_one;
    cout << "请输入添加的商务座数量(中->终)：";
    cin >> temp.business_class_two;
    cout << "请输入添加的商务座价格：";
    cin >> temp.business_class_fee_two;
    cout << "请输入添加的一等座数量(中->终)：";
    cin >> temp.first_class_two;
    cout << "请输入添加的一等座价格：";
    cin >> temp.first_class_fee_two;
    cout << "请输入添加的二等座数量(中->终)：";
    cin >> temp.second_class_two;
    cout << "请输入添加的二等座价格：";
    cin >> temp.second_class_fee_two;
    cout << endl;

    appendNode_train(&pList, &temp);
    //打开文件
    fp = fopen(FILEPATH1, "wb");
    struct Node1* pTemp = pList;
    while (pTemp)
    {
        fwrite(&(pTemp->data), 1, sizeof(struct train), fp);
        pTemp = pTemp->pNext;
    }
    fclose(fp);
    cout << "车辆信息添加成功！";
    deleteList1(&pList);
}

//删除选中的列车信息对应的链表结点
int del_trainNode(struct Node1* current, string a)
{
    FILE* fp = fopen(FILEPATH1, "rb");
    //读取文件内容并存入链表
    struct Node1* pList = NULL;
    int r;
    int flag = 0;
    struct train temp;//临时存储一列火车数据
    while (1)
    {
        r = fread(&temp, 1, sizeof(struct train), fp);
        if (r <= 0)//未读取到数据
        {
            break;
        }
        else//读取到了
        {
            appendNode_train(&pList, &temp);
        }
    }
    fclose(fp);
    if (current->pNext == NULL)
    {
        if (current->data.number == a)
        {
            free(current);
            flag = 1;
            const char* savePath = "1.dat";
            if (remove(savePath) == 0)
            {
                cout << "车次信息删除成功" << endl;
            }
            else
            {
                cout << "删除失败" << endl;
            }
            std::string folderPath = ".";
            std::string fileName = "1.dat";
            std::ofstream outputFile;
            outputFile.open(folderPath + "\\" + fileName);
            return flag;
        }
        else
        {
            cout << "未查找到该列车信息！";
            return flag;
        }
    }
    struct Node1* target = current->pNext;
    if (current->data.number == a)
    {
        current->data = target->data;
        current->pNext = target->pNext;
        free(target);
        cout << "车次信息删除成功！";
        return flag;
    }
    else
    {
        while (target->data.number != a && target->pNext != NULL)
        {
            current = target;
            target = target->pNext;
        }
        if (target->pNext == NULL && target->data.number == a)
        {
            current->pNext = NULL;
            cout << "车次信息删除成功！";
            free(target);
            return flag;
        }
        else if (target->data.number == a && target->pNext != NULL)
        {
            current->pNext = target->pNext;
            free(target);
            cout << "车次信息删除成功！";
            return flag;
        }
        else if (target->data.number != a && target->pNext == NULL)
        {
            cout << "未查找到该列车信息！";
            return flag;
        }
    }
}

//删除指定的乘客信息节点
int del_passengerNode(struct Node2* current, string b, string a)
{
    int sign = 0;
    FILE* fp = fopen(FILEPATH2, "rb");
    if (fp == NULL)
    {
        std::string folderPath = ".";
        std::string fileName = "2.dat";
        std::ofstream outputFile;
        outputFile.open(folderPath + "\\" + fileName);
        outputFile.close();
        fp = fopen(FILEPATH2, "rb");
    }
    //读取文件内容并存入链表
    struct Node2* rList = NULL;
    int r;
    struct passenger temp;//临时存储一列火车数据
    while (1)
    {
        r = fread(&temp, 1, sizeof(struct passenger), fp);
        if (r <= 0)//未读取到数据
        {
            break;
        }
        else//读取到了
        {
            appendNode_passenger(&rList, &temp);
        }
    }
    fclose(fp);
    struct Node2* prev = current;
    if (current->rNext == NULL)
    {
        if (current->data.train_number == a && current->data.ID_number == b)
        {
            free(current);
            int sign = 1;
            const char* savePath = "2.dat";
            if (remove(savePath) == 0)
            {
                cout << "车票信息删除成功" << endl;
            }
            else
            {
                cout << "删除失败" << endl;
            }
            std::string folderPath = ".";
            std::string fileName = "2.dat";
            std::ofstream outputFile;
            outputFile.open(folderPath + "\\" + fileName);
            return sign;
        }
        else
        {
            cout << "未查找到该车票信息！";
            return sign;
        }
    }
    struct Node2* target = current->rNext;
    if (current->data.train_number == a && current->data.ID_number == b)
    {
        current->data = target->data;
        current->rNext = target->rNext;
        free(target);
        cout << "车票信息删除成功！";
        return sign;
    }
    else
    {
        while ((target->data.train_number != a || target->data.ID_number != b) && target->rNext != NULL)
        {
            current = target;
            target = target->rNext;
        }
        if (target->rNext == NULL && target->data.train_number == a && target->data.ID_number == b)
        {
            current->rNext = NULL;
            cout << "车票信息删除成功！";
            free(target);
            return sign;
        }
        else if (target->data.train_number == a && target->rNext != NULL && target->data.ID_number == b)
        {
            current->rNext = target->rNext;
            free(target);
            cout << "车票信息删除成功！";
            return sign;
        }
        else if ((target->data.train_number != a || target->data.ID_number != b) && target->rNext == NULL)
        {
            cout << "未查找到该车票信息！";
            return sign;
        }
    }
}


//按照车次删除相关的车票信息函数
int del_passengerNode_with_train(struct Node2* current, string a)
{
    int x = 0;
    FILE* fp = fopen(FILEPATH2, "rb");
    if (fp == NULL)
    {
        std::string folderPath = ".";
        std::string fileName = "2.dat";
        std::ofstream outputFile;
        outputFile.open(folderPath + "\\" + fileName);
        outputFile.close();
        fp = fopen(FILEPATH2, "rb");
    }
    //读取文件内容并存入链表
    struct Node2* rList = NULL;
    int r;
    struct passenger rtemp;//临时存储一列火车数据
    while (1)
    {
        r = fread(&rtemp, 1, sizeof(struct passenger), fp);
        if (r <= 0)//未读取到数据
        {
            break;
        }
        else//读取到了
        {
            appendNode_passenger(&rList, &rtemp);
        }
    }
    fclose(fp);
    if (current->rNext == NULL)
    {
        if (current->data.train_number == a)
        {
            x = 1;
            free(current);
            const char* savePath = "2.dat";
            remove(savePath);
            std::string folderPath = ".";
            std::string fileName = "2.dat";
            std::ofstream outputFile;
            outputFile.open(folderPath + "\\" + fileName);
            return x;
        }
        else
        {
            return x;
        }
    }
    struct Node2* target = current->rNext;
    if (current->data.train_number == a)
    {
        current->data = target->data;
        current->rNext = target->rNext;
        free(target);
        return x;
    }
    else
    {
        while (target->data.train_number != a && target->rNext != NULL)
        {
            current = target;
            target = target->rNext;
        }
        if (target->rNext == NULL && target->data.train_number == a)
        {
            current->rNext = NULL;
            free(target);
            return x;
        }
        else if (target->data.train_number == a && target->rNext != NULL)
        {
            current->rNext = target->rNext;
            free(target);
            return x;
        }
        else if (target->data.train_number != a && target->rNext == NULL)
        {
            return x;
        }
    }
}


//删除车次信息
void del_trains()
{
    int flag;
    FILE* fp = fopen(FILEPATH1, "rb");
    if (fp == NULL)
    {
        std::string folderPath = ".";
        std::string fileName = "1.dat";
        std::ofstream outputFile;
        outputFile.open(folderPath + "\\" + fileName);
        outputFile.close();
        fp = fopen(FILEPATH1, "rb");
    }
    //读取文件内容并存入链表
    struct Node1* pList = NULL;
    int r;
    struct train temp;//临时存储一列火车数据
    while (1)
    {
        r = fread(&temp, 1, sizeof(struct train), fp);
        if (r <= 0)//未读取到数据
        {
            break;
        }
        else//读取到了
        {
            appendNode_train(&pList, &temp);
        }
    }
    fclose(fp);
    struct Node1* Q = pList;
    if (Q == NULL)
    {
        cout << "系统中没有车次信息！";
        return;
    }
    string checi;
    cout << "请输入要删除的车次：";
    cin >> checi;
    flag = del_trainNode(pList, checi);
    if (flag == 1)
    {
        return;
    }
    else
    {
        fp = fopen(FILEPATH1, "wb");
        struct Node1* pTemp = pList;
        while (pTemp != NULL)
        {
            fwrite(&(pTemp->data), 1, sizeof(struct train), fp);
            pTemp = pTemp->pNext;
        }
        fclose(fp);
        deleteList1(&pList);
    }

    //删除这趟列车的同时还应将这趟车所售出的车票作废
    int z;
    FILE* tp = fopen(FILEPATH2, "rb");
    if (tp == NULL)
    {
        std::string folderPath = ".";
        std::string fileName = "2.dat";
        std::ofstream outputFile;
        outputFile.open(folderPath + "\\" + fileName);
        outputFile.close();
        tp = fopen(FILEPATH2, "rb");
    }
    //读取文件内容并存入链表
    struct Node2* rList = NULL;
    int b;
    struct passenger rtemp;//临时存储一列火车数据
    while (1)
    {
        b = fread(&rtemp, 1, sizeof(struct passenger), tp);
        if (b <= 0)//未读取到数据
        {
            break;
        }
        else//读取到了
        {
            appendNode_passenger(&rList, &rtemp);
        }
    }
    fclose(tp);
    struct Node2* P = rList;
    if (P == NULL)
    {
        return;
    }
    z = del_passengerNode_with_train(rList, checi);
    if (z == 1)
    {
        return;
    }
    else
    {
        tp = fopen(FILEPATH2, "wb");
        struct Node2* rTemp = rList;
        while (rTemp != NULL)
        {
            fwrite(&(rTemp->data), 1, sizeof(struct passenger), tp);
            rTemp = rTemp->rNext;
        }
        fclose(tp);
        deleteList2(&rList);
    }
}

//#查询列车信息的函数
void ask_trains()
{
    FILE* fp = fopen(FILEPATH1, "rb");
    if (fp == NULL)
    {
        std::string folderPath = ".";
        std::string fileName = "1.dat";
        std::ofstream outputFile;
        outputFile.open(folderPath + "\\" + fileName);
        outputFile.close();
        fp = fopen(FILEPATH1, "rb");
    }
    //读取文件内容并存入链表
    struct Node1* pList = NULL;
    int r;
    struct train temp;//临时存储一列火车数据
    while (1)
    {
        r = fread(&temp, 1, sizeof(struct train), fp);
        if (r <= 0)//未读取到数据
        {
            break;
        }
        else//读取到了
        {
            appendNode_train(&pList, &temp);
        }
    }
    fclose(fp);
    struct Node1* Q = pList;
    if (Q == NULL)
    {
        cout << "系统中没有列车信息！";
        return;
    }
    int a;
    cout << "请选择查询方式(1车次查询，2站点查询，3时间查询)：";
    cin >> a;
    if (a == 1)
    {
        findtrain(pList);
        deleteList1(&pList);
        return;
    }
    else if (a == 2)
    {
        string begin, end;
        string x[20] = {};
        int i = 0;
        int m = 0;
        cout << "请输入起点：";
        cin >> begin;
        cout << "请输入终点：";
        cin >> end;
        find_train_by_station(pList, x, begin, end);
        deleteList1(&pList);
        while (x[i] != "")
        {
            i += 1;
        }
        if (i == 0)
        {
            return;
        }
        cout << "查找的车次如下：";
        cout << endl;
        while (m < i)
        {
            cout << x[m];
            m += 1;
            cout << endl;
        }
        return;
    }
    else if (a == 3)
    {
        string Time;
        string checi[20];
        string a;
        string p[2];
        int style;
        cout << "请输入要查找的时间(输入整点）：";
        cin >> Time;
        cout << "请选择查找的时间类型（1发车时间，2途经时间，3终点时间）";
        cin >> style;
        split(Time, p);
        a = p[0];
        find_train_by_time(pList, a, style, checi);
        deleteList1(&pList);
        return;
    }
    else
    {
        cout << "输入的数字不正确!";
        return;
    }
}

//查询座位信息的函数
void ask_ticket()
{
    FILE* fp = fopen(FILEPATH2, "rb");
    if (fp == NULL)
    {
        std::string folderPath = ".";
        std::string fileName = "2.dat";
        std::ofstream outputFile;
        outputFile.open(folderPath + "\\" + fileName);
        outputFile.close();
        fp = fopen(FILEPATH2, "rb");
    }
    struct Node2* rList = NULL;
    int r;
    struct passenger temp;//临时存储一列火车数据
    while (1)
    {
        r = fread(&temp, 1, sizeof(struct passenger), fp);
        if (r <= 0)//未读取到数据
        {
            break;
        }
        else//读取到了
        {
            appendNode_passenger(&rList, &temp);
        }
    }
    fclose(fp);
    findpassenger(rList);
    deleteList2(&rList);
}


//查询列车当前状态
void ask_if_setout()
{
    //构造实时时钟
    class Clock
    {
    public:
        Clock()
        {
            time_t t = time(nullptr);
            struct tm* pt = localtime(&t);
            _sec = pt->tm_sec;
            _min = pt->tm_min;
            _hour = pt->tm_hour;
        }
        int run_hour()
        {
            clock_t start = clock();
            getLocalTime();
            int a = display_hour();
            clock_t finish = clock();
            this_thread::sleep_for(chrono::milliseconds(1000 - (finish - start)));
            return a;
        }

        int run_minute()
        {
            clock_t start = clock();
            getLocalTime();
            int b = display_minute();
            clock_t finish = clock();
            this_thread::sleep_for(chrono::milliseconds(1000 - (finish - start)));
            return b;
        }
        int display_hour()
        {
            return _hour;
        }
        int display_minute()
        {
            return _min;
        }
        void getLocalTime()  //见说明1
        {
            time_t t = time(nullptr);
            struct tm* pt = localtime(&t);
            _sec = pt->tm_sec;
            _min = pt->tm_min;
            _hour = pt->tm_hour;
        }

        int _sec;
        int _min;
        int _hour;
    };
    Clock c;
    int hour;
    int minute;
    hour = c.run_hour();
    minute = c.run_minute();

    FILE* fp = fopen(FILEPATH1, "rb");
    if (fp == NULL)
    {
        std::string folderPath = ".";
        std::string fileName = "1.dat";
        std::ofstream outputFile;
        outputFile.open(folderPath + "\\" + fileName);
        outputFile.close();
        fp = fopen(FILEPATH1, "rb");
    }
    //读取文件内容并存入链表
    struct Node1* pList = NULL;
    int r;
    struct train temp;//临时存储一列火车数据
    while (1)
    {
        r = fread(&temp, 1, sizeof(struct train), fp);
        if (r <= 0)//未读取到数据
        {
            break;
        }
        else//读取到了
        {
            appendNode_train(&pList, &temp);
        }
    }
    fclose(fp);
    struct Node1* Q = pList;
    if (Q == NULL)
    {
        cout << "系统中没有车次信息！";
        return;
    }
    struct Node1* P = find_train_by_num(pList);
    if (P == NULL) { return; }
    else
    {
        int mx, nx, my, ny, mz, nz;
        string x, y, z;
        string timex[2];
        string timey[2];
        string timez[2];
        x = P->data.begin_time;
        y = P->data.mid_time;
        z = P->data.end_time;
        split(x, timex);
        split(y, timey);
        split(z, timez);
        mx = atoi(timex[0].c_str());
        nx = atoi(timex[1].c_str());
        my = atoi(timey[0].c_str());
        ny = atoi(timey[1].c_str());
        mz = atoi(timez[0].c_str());
        nz = atoi(timez[1].c_str());
        if (hour == mx && minute == nx)
        {
            cout << "该列车正在始发站：";
            cout << P->data.begin_station;
            cout << endl;
            cout << "正在检票！";
            return;
        }
        else if (hour == mx && minute < nx || hour < mx)
        {
            cout << "该列车尚未发车！";
            return;
        }
        else
        {
            if (hour == my && minute == ny)
            {
                cout << "该列车正在途径站:";
                cout << P->data.mid_station;
                cout << endl;
                cout << "正在检票！";
                return;
            }
            else if (hour == my && minute < ny || hour < my)
            {
                cout << "该列车已从始发站:";
                cout << P->data.begin_station;
                cout << " 发出，且尚未到达途径站:";
                cout << P->data.mid_station;
                return;
            }
            else
            {
                if (hour == mz && minute < nz || hour < mz)
                {
                    cout << "该列车已从途径站:";
                    cout << P->data.mid_station;
                    cout << "发出，且尚未到达终点站:";
                    cout << P->data.terminal;
                    return;
                }
                else if (hour == mz && minute == nz)
                {
                    cout << "该列车已到达终点站:";
                    cout << P->data.terminal << endl;
                    cout << "乘客正在下车！";
                    return;
                }
                else
                {
                    cout << "该列车已到达终点站:";
                    cout << P->data.terminal;
                    cout << "，本次旅途已结束！";
                    return;
                }
            }
        }
    }
}

//输入乘客信息的函数
void add_passengers(char m[20], string n, char p[20], char q[20])
{
    FILE* fp = fopen(FILEPATH2, "rb");
    if (fp == NULL)
    {
        std::string folderPath = ".";
        std::string fileName = "2.dat";
        std::ofstream outputFile;
        outputFile.open(folderPath + "\\" + fileName);
        outputFile.close();
        fp = fopen(FILEPATH2, "rb");
    }
    //读取文件内容并存入链表
    struct Node2* rList = NULL;
    int r;
    struct passenger rTemp;//临时存储一列乘客数据
    while (1)
    {
        r = fread(&rTemp, 1, sizeof(struct passenger), fp);
        if (r <= 0)//未读取到数据
        {
            break;
        }
        else//读取到了
        {
            appendNode_passenger(&rList, &rTemp);
        }
    }
    fclose(fp);
    string a, b;
    cout << "请输入姓名：";
    cin >> a;
    cout << "请输入身份证号：";
    cin >> b;
    strcpy(rTemp.name, a.c_str());
    strcpy(rTemp.ID_number, b.c_str());
    strcpy(rTemp.seat_type, m);
    strcpy(rTemp.train_number, n.c_str());
    strcpy(rTemp.begin, p);
    strcpy(rTemp.end, q);
    cout << endl;

    appendNode_passenger(&rList, &rTemp);
    //打开文件
    fp = fopen(FILEPATH2, "wb");
    struct Node2* pTemp = rList;
    while (pTemp != NULL)
    {
        fwrite(&(pTemp->data), 1, sizeof(struct passenger), fp);
        pTemp = pTemp->rNext;
    }
    fclose(fp);
    cout << "乘客信息添加成功！";
    deleteList2(&rList);
}

//买票函数
void add_tickets()
{
    FILE* fp = fopen(FILEPATH1, "rb");
    if (fp == NULL)
    {
        std::string folderPath = ".";
        std::string fileName = "1.dat";
        std::ofstream outputFile;
        outputFile.open(folderPath + "\\" + fileName);
        outputFile.close();
        fp = fopen(FILEPATH1, "rb");
    }
    //读取文件内容并存入链表
    struct Node1* pList = NULL;
    int r;
    string checi1[20] = {};
    struct train temp;//临时存储一列火车数据
    while (1)
    {
        r = fread(&temp, 1, sizeof(struct train), fp);
        if (r <= 0)//未读取到数据
        {
            break;
        }
        else//读取到了
        {
            appendNode_train(&pList, &temp);
        }
    }
    fclose(fp);
    struct Node1* Q = pList;
    if (Q == NULL)
    {
        cout << "系统中没有列车信息！";
        return;
    }
    string begin, end;
    cout << "请输入起点：";
    cin >> begin;
    cout << "请输入终点：";
    cin >> end;
    find_train_by_station(pList, checi1, begin, end);
    string N;
    int M = 0;
    while (checi1[M] != "")
    {
        M += 1;
    }
    if (M == 0)
    {
        return;
    }
    M = 0;
    cout << endl;
    cout << "可供选择的车次：" << endl;
    while (checi1[M] != "")
    {
        cout << checi1[M] << endl;
        M += 1;
    }
    int i = 0;
    bool flag = 0;
    while (flag == 0)
    {
        cout << "请选择要购买的车次：";
        cin >> N;
        while (checi1[i] != N && checi1[i] != "")
        {
            i += 1;
        }
        if (checi1[i] == "")
        {
            cout << "选择的车次有误,请重新选择！";
            cout << endl;
            i = 0;
        }
        else
        {
            flag = 1;
        }
    }
    struct Node1* P = find_train_by_num_given(pList, N);
    string a1, a2, a3;
    string x1, x2, x3, y1, y2, y3;
    string n1, n2, n3, m1, m2, m3;
    char zuowei[20];
    int A1, A2, A3, B1, B2, B3;
    int a, b, c, d, e;
    char m[20];
    char n[20];
    char p[20];
    char q[20];
    a1 = P->data.begin_station;
    a2 = P->data.mid_station;
    a3 = P->data.terminal;
    x1 = P->data.business_class_one;
    x2 = P->data.first_class_one;
    x3 = P->data.second_class_one;
    y1 = P->data.business_class_two;
    y2 = P->data.first_class_two;
    y3 = P->data.second_class_two;
    n1 = P->data.business_class_fee_one;
    n2 = P->data.first_class_fee_one;
    n3 = P->data.second_class_fee_one;
    m1 = P->data.business_class_fee_two;
    m2 = P->data.first_class_fee_two;
    m3 = P->data.second_class_fee_two;
    A1 = atoi(x1.c_str());
    A2 = atoi(x2.c_str());
    A3 = atoi(x3.c_str());
    B1 = atoi(y1.c_str());
    B2 = atoi(y2.c_str());
    B3 = atoi(y3.c_str());
    if (begin == a1 && end == a2)
    {
        strcpy(p, begin.c_str());
        strcpy(q, end.c_str());
        cout << "请选择座位类型(1商务座，2一等座，3二等座）：";
        cin >> a;
        switch (a)
        {
        case 1:
            if (A1 != 0)
            {
                strcpy(zuowei, "商务座");
                b = A1 - 1; itoa(b, m, 10);
                strcpy(P->data.business_class_one, m);
                cout << "需要支付：" << n1 << "元！";
                cout << endl;
                fp = fopen(FILEPATH1, "wb");
                struct Node1* pTemp = pList;
                while (pTemp)
                {
                    fwrite(&(pTemp->data), 1, sizeof(struct train), fp);
                    pTemp = pTemp->pNext;
                }
                fclose(fp);
                add_passengers(zuowei, N, p, q);
                cout << "购票成功！";
                cout << endl;
                deleteList1(&pList);
                Sleep(2000); break;
            }
            else { cout << "该趟商务票已售罄！"; Sleep(2000); break; }
        case 2:
            if (A2 != 0)
            {
                strcpy(zuowei, "一等座");
                b = A2 - 1; itoa(b, m, 10);
                strcpy(P->data.first_class_one, m);
                cout << "需要支付：" << n2 << "元！";
                cout << endl;
                fp = fopen(FILEPATH1, "wb");
                struct Node1* pTemp = pList;
                while (pTemp)
                {
                    fwrite(&(pTemp->data), 1, sizeof(struct train), fp);
                    pTemp = pTemp->pNext;
                }
                fclose(fp);
                add_passengers(zuowei, N, p, q);
                cout << "购票成功！";
                deleteList1(&pList);
                Sleep(2000); break;
            }
            else { cout << "该趟一等票已售罄！"; Sleep(2000); break; }
        case 3:
            if (A3 != 0)
            {
                strcpy(zuowei, "二等座");
                b = A3 - 1; itoa(b, m, 10);
                strcpy(P->data.second_class_one, m);
                cout << "需要支付：" << n3 << "元！";
                cout << endl;
                fp = fopen(FILEPATH1, "wb");
                struct Node1* pTemp = pList;
                while (pTemp)
                {
                    fwrite(&(pTemp->data), 1, sizeof(struct train), fp);
                    pTemp = pTemp->pNext;
                }
                fclose(fp);
                add_passengers(zuowei, N, p, q);
                cout << "购票成功！";
                deleteList1(&pList);
                Sleep(2000); break;
            }
            else { cout << "该趟二等票已售罄！"; Sleep(2000); break; }
        default:cout << "请输入1-3的数字！"; Sleep(2000); break;
        };
    }
    else if (begin == a2 && end == a3)
    {
        strcpy(p, begin.c_str());
        strcpy(q, end.c_str());
        cout << "请选择座位类型(1商务座，2一等座，3二等座）：";
        cin >> a;
        switch (a)
        {
        case 1:
            if (B1 != 0)
            {
                strcpy(zuowei, "商务座");
                b = B1 - 1; itoa(b, m, 10);
                strcpy(P->data.business_class_two, m);
                cout << "需要支付：" << m1 << "元！";
                cout << endl;
                fp = fopen(FILEPATH1, "wb");
                struct Node1* pTemp = pList;
                while (pTemp)
                {
                    fwrite(&(pTemp->data), 1, sizeof(struct train), fp);
                    pTemp = pTemp->pNext;
                }
                fclose(fp);
                add_passengers(zuowei, N, p, q);
                cout << "购票成功！";
                deleteList1(&pList);
                Sleep(2000); break;
            }
            else { cout << "该趟商务票已售罄！"; Sleep(2000); break; }
        case 2:
            if (B2 != 0)
            {
                strcpy(zuowei, "一等座");
                b = B2 - 1; itoa(b, m, 10);
                strcpy(P->data.first_class_two, m);
                cout << "需要支付：" << m2 << "元！";
                cout << endl;
                fp = fopen(FILEPATH1, "wb");
                struct Node1* pTemp = pList;
                while (pTemp)
                {
                    fwrite(&(pTemp->data), 1, sizeof(struct train), fp);
                    pTemp = pTemp->pNext;
                }
                fclose(fp);
                add_passengers(zuowei, N, p, q);
                cout << "购票成功！";
                deleteList1(&pList);
                Sleep(2000); break;
            }
            else { cout << "该趟一等票已售罄！"; Sleep(2000); break; }
        case 3:
            if (B3 != 0)
            {
                strcpy(zuowei, "二等座");
                b = B3 - 1; itoa(b, m, 10);
                strcpy(P->data.second_class_two, m);
                cout << "需要支付：" << m3 << "元！";
                cout << endl;
                fp = fopen(FILEPATH1, "wb");
                struct Node1* pTemp = pList;
                while (pTemp)
                {
                    fwrite(&(pTemp->data), 1, sizeof(struct train), fp);
                    pTemp = pTemp->pNext;
                }
                fclose(fp);
                add_passengers(zuowei, N, p, q);
                cout << "购票成功！";
                deleteList1(&pList);
                Sleep(2000); break;
            }
            else { cout << "该趟二等票已售罄！"; Sleep(2000); break; }
        default:cout << "请输入1-3的数字！"; Sleep(2000); break;
        };
    }
    else if (begin == a1 && end == a3)
    {
        strcpy(p, begin.c_str());
        strcpy(q, end.c_str());
        cout << "请选择座位类型(1商务座，2一等座，3二等座）：";
        cin >> a;
        switch (a)
        {
        case 1:
            if (A1 != 0 && B1 != 0)
            {
                strcpy(zuowei, "商务座");
                d = stoi(m1); e = stoi(n1);
                b = A1 - 1; c = B1 - 1;
                itoa(b, m, 10); itoa(c, n, 10);
                strcpy(P->data.business_class_one, m);
                strcpy(P->data.business_class_two, n);
                cout << "需要支付：" << d + e << "元！";
                cout << endl;
                fp = fopen(FILEPATH1, "wb");
                struct Node1* pTemp = pList;
                while (pTemp)
                {
                    fwrite(&(pTemp->data), 1, sizeof(struct train), fp);
                    pTemp = pTemp->pNext;
                }
                fclose(fp);
                add_passengers(zuowei, N, p, q);
                cout << "购票成功！";
                deleteList1(&pList);
                Sleep(2000); break;
            }
            else { cout << "该趟商务票已售罄！"; Sleep(2000); break; }
        case 2:
            if (A2 != 0 && B2 != 0)
            {
                strcpy(zuowei, "一等座");
                d = stoi(m2); e = stoi(n2);
                b = A2 - 1; c = B2 - 1;
                itoa(b, m, 10); itoa(c, n, 10);
                strcpy(P->data.first_class_one, m);
                strcpy(P->data.first_class_two, n);
                cout << "需要支付：" << d + e << "元！";
                cout << endl;
                fp = fopen(FILEPATH1, "wb");
                struct Node1* pTemp = pList;
                while (pTemp)
                {
                    fwrite(&(pTemp->data), 1, sizeof(struct train), fp);
                    pTemp = pTemp->pNext;
                }
                fclose(fp);
                add_passengers(zuowei, N, p, q);
                cout << "购票成功！";
                deleteList1(&pList);
                Sleep(2000); break;
            }
            else { cout << "该趟一等票已售罄！"; Sleep(2000); break; }
        case 3:
            if (A3 != 0 && B3 != 0)
            {
                strcpy(zuowei, "二等座");
                d = stoi(m3); e = stoi(n3);
                b = A3 - 1; c = B3 - 1;
                itoa(b, m, 10); itoa(c, n, 10);
                strcpy(P->data.second_class_one, m);
                strcpy(P->data.second_class_two, n);
                cout << "需要支付：" << d + e << "元！";
                cout << endl;
                fp = fopen(FILEPATH1, "wb");
                struct Node1* pTemp = pList;
                while (pTemp)
                {
                    fwrite(&(pTemp->data), 1, sizeof(struct train), fp);
                    pTemp = pTemp->pNext;
                }
                fclose(fp);
                add_passengers(zuowei, N, p, q);
                cout << "购票成功！";
                deleteList1(&pList);
                Sleep(2000); break;
            }
            else { cout << "该趟二等票已售罄！"; Sleep(2000); break; }
        default:cout << "请输入1-3的数字！"; Sleep(2000); break;
        };
    }
}

//按已知身份证查找乘客信息的函数
int find_passenger_by_ID_given(struct Node2* current, string sfz, string* a, int flag)
{
    while (current != NULL)
    {
        if (current->data.ID_number != sfz)
        {
            current = current->rNext;
        }
        else
        {
            a[flag] = current->data.train_number;
            flag += 1;
            current = current->rNext;
        }
    }
    if (flag == 0)
    {
        cout << "没有查找到对应乘客！";
        return flag;
    }
    else
    {
        return flag;
    }
}

//通过身份证号、车次对乘客信息进行精准查找
struct Node2* find_passenger_by_double_number(struct Node2* current, string sfz, string checi)
{
    FILE* fp = fopen(FILEPATH2, "rb");
    if (fp == NULL)
    {
        cout << "该文件不存在！";
        return NULL;
    }
    //读取文件内容并存入链表
    struct Node2* rList = NULL;
    int r;
    struct passenger temp;//临时存储一列火车数据
    while (1)
    {
        r = fread(&temp, 1, sizeof(struct passenger), fp);
        if (r <= 0)//未读取到数据
        {
            break;
        }
        else//读取到了
        {
            appendNode_passenger(&rList, &temp);
        }
    }
    fclose(fp);
    while (current != NULL)
    {
        if (current->data.ID_number != sfz || current->data.train_number != checi)
        {
            current = current->rNext;
        }
        else
        {
            return current;
        }
    }
    return NULL;
}

//修改列车节点信息的函数
void fix_train_node(struct Node1* current, string a, string b, string c, string d)
{
    int x;
    FILE* fp = fopen(FILEPATH1, "rb");
    //读取文件内容并存入链表
    struct Node1* pList = NULL;
    int r;
    struct train Temp;//临时存储一列火车数据
    while (1)
    {
        r = fread(&Temp, 1, sizeof(struct train), fp);
        if (r <= 0)//未读取到数据
        {
            break;
        }
        else//读取到了
        {
            appendNode_train(&pList, &Temp);
        }
    }
    fclose(fp);
    if (current != NULL && current->data.number != a)
    {
        current = current->pNext;
    }
    else if (current == NULL)
    {
        cout << "未查找到相关列车信息！";
        return;
    }
    else if (current->data.number == a)
    {
        if (b == "商务座")
        {
            if (current->data.begin_station == c && current->data.mid_station == d)
            {
                x = atoi(current->data.business_class_one);
                x += 1;
                itoa(x, current->data.business_class_one, 10);
            }
            else if (current->data.mid_station == c && current->data.terminal == d)
            {
                x = atoi(current->data.business_class_two);
                x += 1;
                itoa(x, current->data.business_class_two, 10);
            }
            else
            {
                x = atoi(current->data.business_class_one);
                x += 1;
                itoa(x, current->data.business_class_one, 10);
                x = atoi(current->data.business_class_two);
                x += 1;
                itoa(x, current->data.business_class_two, 10);
            }
        }
        else if (b == "一等座")
        {
            if (current->data.begin_station == c && current->data.mid_station == d)
            {
                x = atoi(current->data.first_class_one);
                x += 1;
                itoa(x, current->data.first_class_one, 10);
            }
            else if (current->data.mid_station == c && current->data.terminal == d)
            {
                x = atoi(current->data.first_class_two);
                x += 1;
                itoa(x, current->data.first_class_two, 10);
            }
            else
            {
                x = atoi(current->data.first_class_one);
                x += 1;
                itoa(x, current->data.first_class_one, 10);
                x = atoi(current->data.first_class_two);
                x += 1;
                itoa(x, current->data.first_class_two, 10);
            }
        }
        else
        {
            if (current->data.begin_station == c && current->data.mid_station == d)
            {
                x = atoi(current->data.second_class_one);
                x += 1;
                itoa(x, current->data.second_class_one, 10);
            }
            else if (current->data.mid_station == c && current->data.terminal == d)
            {
                x = atoi(current->data.second_class_two);
                x += 1;
                itoa(x, current->data.second_class_two, 10);
            }
            else
            {
                x = atoi(current->data.second_class_one);
                x += 1;
                itoa(x, current->data.second_class_one, 10);
                x = atoi(current->data.second_class_two);
                x += 1;
                itoa(x, current->data.second_class_two, 10);
            }
        }
        return;
    }
}

//退票函数
void del_tickets()
{
    int v;
    FILE* fp = fopen(FILEPATH2, "rb");
    if (fp == NULL)
    {
        std::string folderPath = ".";
        std::string fileName = "2.dat";
        std::ofstream outputFile;
        outputFile.open(folderPath + "\\" + fileName);
        outputFile.close();
        fp = fopen(FILEPATH2, "rb");
    }
    //读取文件内容并存入链表
    struct Node2* rList = NULL;
    int r;
    struct passenger temp;//临时存储一列火车数据
    while (1)
    {
        r = fread(&temp, 1, sizeof(struct passenger), fp);
        if (r <= 0)//未读取到数据
        {
            break;
        }
        else//读取到了
        {
            appendNode_passenger(&rList, &temp);
        }
    }
    fclose(fp);

    FILE* tp = fopen(FILEPATH1, "rb");
    if (tp == NULL)
    {
        std::string folderPath = ".";
        std::string fileName = "1.dat";
        std::ofstream outputFile;
        outputFile.open(folderPath + "\\" + fileName);
        outputFile.close();
        tp = fopen(FILEPATH1, "rb");
    }
    //读取文件内容并存入链表
    struct Node1* pList = NULL;
    int z;
    struct train Temp;//临时存储一列火车数据
    while (1)
    {
        z = fread(&Temp, 1, sizeof(struct train), tp);
        if (z <= 0)//未读取到数据
        {
            break;
        }
        else//读取到了
        {
            appendNode_train(&pList, &Temp);
        }
    }
    fclose(tp);

    struct Node1* P = pList;
    if (P == NULL)
    {
        cout << "系统中没有车票信息！";
        return;
    }

    struct Node2* Q = rList;
    if (Q == NULL)
    {
        cout << "系统中没有乘客信息！";
        return;
    }
    string sfz;
    cout << "请输入要退票的乘客的身份证：";
    cin >> sfz;
    int flag = 0;
    string x[10];
    flag = find_passenger_by_ID_given(rList, sfz, x, flag);
    if (flag == 0)
    {
        return;
    }
    cout << "可退票的车次如下：" << endl;
    for (int i = 0; i < flag; i++)
    {
        cout << x[i];
        cout << endl;
    }
    cout << "请选择需要退票的车次：";
    string t;
    cin >> t;
    int q = 0;
    while (q < flag)
    {
        if (t == x[q])
        {
            break;
        }
        else
        {
            q += 1;
        }
    }
    if (q == flag)
    {
        cout << "输入的车次错误！";
        return;
    }
    struct Node2* M = find_passenger_by_double_number(rList, sfz, t);
    fix_train_node(pList, M->data.train_number, M->data.seat_type, M->data.begin, M->data.end);
    fp = fopen(FILEPATH1, "wb");
    struct Node1* rtemp = pList;
    while (rtemp != NULL)
    {
        fwrite(&(rtemp->data), 1, sizeof(struct train), fp);
        rtemp = rtemp->pNext;
    }
    fclose(fp);
    deleteList1(&pList);
    //对乘客文件中的信息进行修改
    v = del_passengerNode(rList, M->data.ID_number, M->data.train_number);
    if (v == 1)
    {
        return;
    }
    else
    {
        fp = fopen(FILEPATH2, "wb");
        struct Node2* ptemp = rList;
        while (ptemp != NULL)
        {
            fwrite(&(ptemp->data), 1, sizeof(struct passenger), fp);
            ptemp = ptemp->rNext;
        }
        fclose(fp);
        deleteList2(&rList);
    }
}

//管理员界面设计
void Welcome1()
{
    int n;
    while (1)
    {
        system("cls");
        cout << "你好，管理员！\n";
        cout << "********************************\n";
        cout << "*** 欢迎使用高铁票务管理系统 ***\n";
        cout << "********************************\n";
        cout << "*       1.添加客运线信息       *\n";
        cout << "*       2.删除客运线信息       *\n";
        cout << "*       3.显示所有列车站点     *\n";
        cout << "*       4.查看所有座位数量     *\n";
        cout << "*       5.查看所有车票信息     *\n";
        cout << "*       6.退出系统             *\n";
        cout << "********************************\n";
        cout << "请选择：";
        cin >> n;
        cout << endl;
        switch (n)
        {
        case 1: add_trains(); cout << endl; Sleep(1000); break;
        case 2: del_trains(); cout << endl; Sleep(1000); break;
        case 3: showAlltrains(); cout << endl; Sleep(4000); break;
        case 4:showAllSeats_num(); cout << endl; Sleep(4000); break;
        case 5:showAllTickets(); cout << endl; Sleep(4000); break;
        case 6: cout << "操作结束！"; Sleep(1000); exit(1); break;
        default:break;
        };
    }
}

//
void Welcome2()
{
    int m;
    while (1)
    {
        system("cls");
        cout << "你好，乘客！\n";
        cout << "********************************\n";
        cout << "*** 欢迎使用高铁客运订票系统 ***\n";
        cout << "********************************\n";
        cout << "*       1.购买车票             *\n";
        cout << "*       2.退订车票             *\n";
        cout << "*       3.显示座位价格表       *\n";
        cout << "*       4.显示所有列车站点     *\n";
        cout << "*       5.显示所有座位数量     *\n";
        cout << "*       6.查询车票信息         *\n";
        cout << "*       7.查询列车信息         *\n";
        cout << "*       8.查询车次当前状态     *\n";
        cout << "*       9.退出系统             *\n";
        cout << "********************************\n";
        cout << "请选择：";
        cin >> m;
        cout << endl;
        switch (m)
        {
        case 1: add_tickets(); cout << endl; Sleep(1000); break;
        case 2: del_tickets(); cout << endl; Sleep(1000); break;
        case 3: showAllSeats(); cout << endl; Sleep(4000); break;
        case 4: showAlltrains(); cout << endl; Sleep(4000); break;
        case 5:showAllSeats_num(); cout << endl; Sleep(4000); break;
        case 6: ask_ticket(); cout << endl; Sleep(4000); break;
        case 7: ask_trains(); cout << endl; Sleep(4000); break;
        case 8: ask_if_setout(); cout << endl; Sleep(4000); break;
        case 9: cout << "操作结束！"; Sleep(1000); exit(1); break;
        default:break;
        };
    }
}

//主函数部分
int main()
{
    int x;
    bool flag = 0;
    while (flag == 0)
    {
        cout << "请选择身份(1管理员，2乘客）：";
        cin >> x;
        if (x == 1)
        {
            flag = 1;
            Welcome1();
        }
        else if (x == 2)
        {
            flag = 1;
            Welcome2();
        }
        else
        {
            cout << "请输入正确的数字！";
            cout << endl;
        }
    }
    return 0;
}

