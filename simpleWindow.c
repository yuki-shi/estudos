#include <windows.h>

// nome do window class
const char g_szClassName[] = "myWindowClass";

// Step 4: Window Procedure
// todas as mensagens vêm para cá para serem processadas! o cérebro!
LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
    switch(msg)
    {
        case WM_CLOSE:
            DestroyWindow(hwnd);
        break;
        case WM_DESTROY:
            PostQuitMessage(0);
        break;
        default:
            return DefWindowProc(hwnd, msg, wParam, lParam);
    }
    return 0;
}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
    // WNDCLASSEX é uma structure! aqui inicializo seus parâmetros para 0
    // HWND é um HANDLE, uma representação de um objeto no Win32, como arquivo, evento, ect.
    WNDCLASSEX wc = {0};
    HWND hwnd;
    MSG msg;

    // Step 1: Registering the Window Class
    // Window Class guarda informação acerca da janela

    wc.cbSize = sizeof(WNDCLASSEX);
    wc.style = 0;
    wc.lpfnWndProc = WndProc;
    wc.cbClsExtra = 0;
    wc.cbWndExtra = 0;
    wc.hInstance = hInstance;
    wc.hIcon = LoadIcon(NULL, IDI_APPLICATION);
    wc.hCursor = LoadCursor(NULL, IDC_ARROW);
    wc.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
    wc.lpszMenuName = NULL;
    wc.lpszClassName = g_szClassName;
    wc.hIconSm = LoadIcon(NULL, IDI_APPLICATION);

    // aqui validamos o structure
    if(!RegisterClassEx(&wc))
    {
        MessageBox(NULL, "Window Registration Failed!", "Error!", MB_ICONEXCLAMATION | MB_OK);
        return 0;
    }

    // Step 2: Creating the Window
    hwnd = CreateWindowEx(
        WS_EX_CLIENTEDGE,
        g_szClassName,
        "The title of my window",
        WS_OVERLAPPEDWINDOW,
        CW_USEDEFAULT, CW_USEDEFAULT, 240, 120,
        NULL, NULL, hInstance, NULL);

    // aqui validamos a função
    if(hwnd == NULL)
    {
        MessageBox(NULL, "Window Creation Failed!", "Error!", MB_ICONEXCLAMATION | MB_OK);
        return 0;
    }

    // configura como a janela deve ser apresentada
    ShowWindow(hwnd, nCmdShow);
    // handle para a janela ser atualizada
    UpdateWindow(hwnd);

    // Step 3: Message Loop
    // é um ponto de controle! o coração!

    // GetMessage() pega as mensagens da aplicação, sendo que cada uma é gerada com um evento do usuário
    // aqui pegamos cada mensagem da queue para processar
    while(GetMessage(&msg, NULL, 0, 0) > 0)
    {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }
    return msg.wParam;
}