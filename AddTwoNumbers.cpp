/*
You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order, and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     long long val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(long long  x) : val(x), next(nullptr) {}
 *     ListNode(long long  x, ListNode *next) : val(x), next(next) {}
 * };
 */

#include <math.h>

struct ListNode {
    long long val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(long long  x) : val(x), next(nullptr) {}
    ListNode(long long  x, ListNode* next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {

        // Make current cursors for each list 
        ListNode* current1 = l1;
        ListNode* current2 = l2;

        // Declare 3 long long for each list's number and a counter
        long long num1 = 0;
        long long num2 = 0;
        long long num3 = 0;
        long long i = 0;

        // Iterate over the first linked list to get the first number
        while (current1 != nullptr) {
            if (i == 0) {
                num1 += current1->val;
                current1 = current1->next;
                i++;
            }
            else {
                num1 += current1->val * pow(10, i);
                current1 = current1->next;
                i++;
            }
        }
        // Iterate over the second linked list to get the second number
        i = 0;
        while (current2 != nullptr) {
            if (i == 0) {
                num2 += current2->val;
                current2 = current2->next;
                i++;
            }
            else {
                num2 += current2->val * pow(10, i);
                current2 = current2->next;
                i++;
            }
        }
        // Add up the two numnbers to get the sum
        num3 = num2 + num1;

        // Calculate the number of digits in the final number (Make sure to handle if the number is 0)
        long long numDigits = num3 == 0 ? 1 : (log10(num3) + 1);

        // Create a new linked list and cursor
        ListNode* l3 = nullptr;
        ListNode* current3 = nullptr;

        // Add each digit to the linked list, in reverse
        for (long long i = 0; i < numDigits; i++) {
            if (l3 == nullptr) {
                l3 = new ListNode(num3 % 10);
                current3 = l3;
            }
            else {
                current3->next = new ListNode(num3 % 10);
                current3 = current3->next;
            }
            num3 /= 10;
        }
        // Return new linked list
        return l3;
    }
};