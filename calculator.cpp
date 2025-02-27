#if defined(UNICODE) && !defined(_UNICODE)
    #define _UNICODE
#elif defined(_UNICODE) && !defined(UNICODE)
    #define UNICODE
#endif

#include <tchar.h>
#include <stdio.h>
#include <windows.h>

/*  Declare Windows procedure  */
LRESULT CALLBACK WindowProcedure (HWND, UINT, WPARAM, LPARAM);

HWND textfield, button ;

/*  Make the class name into a global variable  */
TCHAR szClassName[ ] = _T("CodeBlocksWindowsApp");
char textSaved[20];
char textSaved1[20];
HWND TextBox,TextBox1;
int WINAPI WinMain (HINSTANCE hThisInstance,
                     HINSTANCE hPrevInstance,
                     LPSTR lpszArgument,
                     int nCmdShow)
{
    HWND hwnd;               /* This is the handle for our window */
    MSG messages;            /* Here messages to the application are saved */
    WNDCLASSEX wincl;        /* Data structure for the windowclass */

    /* The Window structure */
    wincl.hInstance = hThisInstance;
    wincl.lpszClassName = szClassName;
    wincl.lpfnWndProc = WindowProcedure;      /* This function is called by windows */
    wincl.style = CS_DBLCLKS;                 /* Catch double-clicks */
    wincl.cbSize = sizeof (WNDCLASSEX);

    /* Use default icon and mouse-pointer */
    wincl.hIcon = LoadIcon (NULL, IDI_APPLICATION);
    wincl.hIconSm = LoadIcon (NULL, IDI_APPLICATION);
    wincl.hCursor = LoadCursor (NULL, IDC_ARROW);
    wincl.lpszMenuName = NULL;                 /* No menu */
    wincl.cbClsExtra = 0;                      /* No extra bytes after the window class */
    wincl.cbWndExtra = 0;                      /* structure or the window instance */
    /* Use Windows's default colour as the background of the window */
    wincl.hbrBackground = CreateSolidBrush(RGB(255, 0, 0));


    /* Register the window class, and if it fails quit the program */
    if (!RegisterClassEx (&wincl))
        return 0;

    /* The class is registered, let's create the program*/
    hwnd = CreateWindowEx (
           0,                   /* Extended possibilites for variation */
           szClassName,         /* Classname */
           _T("Code::Blocks Template Windows App"),       /* Title Text */
           WS_OVERLAPPEDWINDOW, /* default window */
           CW_USEDEFAULT,       /* Windows decides the position */
           CW_USEDEFAULT,       /* where the window ends up on the screen */
           544,                 /* The programs width */
           375,                 /* and height in pixels */
           HWND_DESKTOP,        /* The window is a child-window to desktop */
           NULL,                /* No menu */
           hThisInstance,       /* Program Instance handler */
           NULL                 /* No Window Creation data */
           );

    /* Make the window visible on the screen */
    ShowWindow (hwnd, nCmdShow);

    /* Run the message loop. It will run until GetMessage() returns 0 */
    while (GetMessage (&messages, NULL, 0, 0))
    {
        /* Translate virtual-key messages into character messages */
        TranslateMessage(&messages);
        /* Send message to WindowProcedure */
        DispatchMessage(&messages);
    }

    /* The program return-value is 0 - The value that PostQuitMessage() gave */
    return messages.wParam;
}


/*  This function is called by the Windows function DispatchMessage()  */

LRESULT CALLBACK WindowProcedure (HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch (message)                  /* handle the messages */
    {
        case WM_CREATE:


            textfield = CreateWindow("STATIC",
                              "Please input two numbers",
                              WS_VISIBLE | WS_CHILD | WS_BORDER,
                              120,10,200,20,
                              hwnd, NULL,NULL,NULL);


            TextBox = CreateWindow("EDIT",
                                   "",
                                   WS_BORDER | WS_CHILD | WS_VISIBLE,
                                   150,50 ,100, 20,
                                   hwnd, NULL, NULL, NULL);

            TextBox1 = CreateWindow("EDIT",
                                   "",
                                   WS_BORDER | WS_CHILD | WS_VISIBLE,
                                   150,100 ,100, 20,
                                   hwnd, NULL, NULL, NULL);

           CreateWindow("BUTTON",
                       "+",
                       WS_VISIBLE | WS_CHILD | WS_BORDER,
                       120, 150, 20, 20,
                       hwnd, (HMENU) 1, NULL, NULL);

            CreateWindow("BUTTON",
                       "-",
                       WS_VISIBLE | WS_CHILD | WS_BORDER,
                       160, 150, 20, 20,
                       hwnd, (HMENU) 2, NULL, NULL);

            CreateWindow("BUTTON",
                       "*",
                       WS_VISIBLE | WS_CHILD | WS_BORDER,
                       200, 150, 20, 20,
                       hwnd, (HMENU) 3, NULL, NULL);

            CreateWindow("BUTTON",
                       "/",
                       WS_VISIBLE | WS_CHILD | WS_BORDER,
                       240, 150, 20, 20,
                       hwnd, (HMENU) 4, NULL, NULL);


        break;
        case WM_COMMAND:

            switch (LOWORD(wParam))
            {
                case 1:{
                    int gwtstat=0;
                    double a;
                    char b[999];
                    char *t = &textSaved[0];
                    gwtstat = GetWindowText(TextBox, &textSaved[0], 20);
                    char *t1 = &textSaved1[0];
                    gwtstat = GetWindowText(TextBox1, &textSaved1[0], 20);
                    a = atof(textSaved)+ atof(textSaved1);
                    sprintf(b, "%f", a);
                    ::MessageBox(hwnd,b, textSaved, MB_OK);

                break;}
                  case 2:{
                    int gwtstat=0;
                    double a;
                    char b[999];
                    char *t = &textSaved[0];
                    gwtstat = GetWindowText(TextBox, &textSaved[0], 20);
                    char *t1 = &textSaved1[0];
                    gwtstat = GetWindowText(TextBox1, &textSaved1[0], 20);
                    a = atof(textSaved)- atof(textSaved1);
                    sprintf(b, "%f", a);
                    ::MessageBox(hwnd,b, textSaved, MB_OK);

                break;}
                  case 3:{
                    int gwtstat=0;
                    double a;
                    char b[999];
                    char *t = &textSaved[0];
                    gwtstat = GetWindowText(TextBox, &textSaved[0], 20);
                    char *t1 = &textSaved1[0];
                    gwtstat = GetWindowText(TextBox1, &textSaved1[0], 20);
                    a = atof(textSaved)* atof(textSaved1);
                    sprintf(b, "%f", a);
                    ::MessageBox(hwnd,b, textSaved, MB_OK);

                break;}
                  case 4:{
                    int gwtstat=0;
                    double a;
                    char b[999];
                    char *t = &textSaved[0];
                    gwtstat = GetWindowText(TextBox, &textSaved[0], 20);
                    char *t1 = &textSaved1[0];
                    gwtstat = GetWindowText(TextBox1, &textSaved1[0], 20);
                    a = atof(textSaved)/ atof(textSaved1);
                    sprintf(b, "%f", a);
                    ::MessageBox(hwnd,b, textSaved, MB_OK);

                break;}
            }
                /* send a WM_QUIT to the message queue */
            break;
        case WM_DESTROY:
        default:                      /* for messages that we don't deal with */
            return DefWindowProc (hwnd, message, wParam, lParam);
    }

    return 0;
}
