/*fraction_math.c for Project 5
 * Program Design
 */

#include <stdio.h>

int main(void)
{
  int num1, denom1, num2, denom2, result_num, result_denom;
  char operator;

  printf("Enter two fractions separated by a +, -, * or / sign: ");
  scanf("%d/%d %c%d/%d", &num1, &denom1, &operator, &num2, &denom2);

  switch (operator) {
    case '+':
      result_num = num1 * denom2 + num2 * denom1;
      result_denom = denom1 * denom2;
      printf("The sum is %d/%d\n", result_num, result_denom);
      break;
    case '-':
      result_num = num1 * denom2 - num2 * denom1;
      result_denom = denom1 * denom2;
      printf("The difference is %d/%d\n", result_num, result_denom);
      break;
    case '*':
      result_num = num1 * num2;
      result_denom = denom1 * denom2;
      printf("The product is %d/%d\n", result_num, result_denom);
      break;
    case '/':
      result_num = num1 * denom2;
      result_denom = denom1 * num2;
      printf("The quotient is %d/%d\n", result_num, result_denom);
      break;
    default:
      printf("Unrecognized operator: %c\n", operator);
  }

  return 0;
}
