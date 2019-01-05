#include <stdio.h>

int main()
{
    int i, j, prem, space, ani_num, env_friend, test_case, farmer_num;
    int arr[20];
    while(scanf("%d", &test_case) == 1)
    {
        for(i = 0; i < test_case; i++)
        {
            prem = 0;
            scanf("%d", &farmer_num);
            for(j = 0; j < farmer_num; j++)
            {
                scanf("%d%d%d", &space, &ani_num, &env_friend);
                prem += space * env_friend;
            }
            arr[i] = prem;
        }
    }
    for(i = 0; i < test_case; i++)
    {
        printf("%d\n", arr[i]);
    }
    return 0;
}
