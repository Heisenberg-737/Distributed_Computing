#include "IDL.h"
#include <stdio.h>
float compute_6(char *host, float a, float b, char op)
{
    CLIENT *client_object;
    float *result;
    values oper_6_arg;
    oper_6_arg.num1 = a;
    oper_6_arg.num2 = b;
    oper_6_arg.operation = op;
    client_object = client_object_create(host, COMPUTE, COMPUTE_VERS,
                                         "udp");
    if (client_object == NULL)
    {
        client_object_pcreateerror(host);
        exit(1);
    }
    if (op == '+')
        result = add_6(&oper_6_arg, client_object);
    else if (op == '-')
        result = sub_6(&oper_6_arg, client_object);
    else if (op == '*')
        result = mul_6(&oper_6_arg, client_object);
    else if (op == '/')
    {
        if (b == 0)
        {
            printf("Division by Zero is Invalid !!!\n");
            exit(1);
        }
        result = div_6(&oper_6_arg, client_object);
    }
    if (result == (float *)NULL)
    {
        client_object_perror(client_object, "call failed");
    }
    client_object_destroy(client_object);
    return (*result);
}
int main(int argc, char *argv[])
{
    char *host;
    float number1, number2;
    char oper;
    printf("Enter the first number:\n");
    scanf("%f", &number1);
    printf("Enter the operator (+, -, *, /):\n");
    scanf("%s", &oper);
    printf("Enter the second number:\n");
    scanf("%f", &number2);
    host = argv[1];
    printf("%f %s %f = %f\n", number1, oper, number2, compute_6(host, number1, number2, oper));
    exit(0);
}
