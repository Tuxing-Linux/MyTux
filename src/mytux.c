#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include "sprites.h"

time_t ultimo_tempo;

int opcao = 1;
int fome = 0;
int energia = 100;
int love = 0;

SDL_Surface* screen = NULL; //tela onde sera inscrita as imagens
SDL_Surface* spr_normal = NULL; //sprite normal
SDL_Surface* spr_loving = NULL; //sprite amor
SDL_Surface* spr_burger = NULL; //sprite comendo hamburguer
SDL_Surface* spr_cake = NULL;   //sprite comendo bolo

// Fonte bitmap 8x8 minima (A-Z, 0-9, :, [, ], espaco)  //guarda o desenho dos caracteres
const unsigned char font8x8[40][8] = {
    {0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00}, //  
    {0x3E,0x63,0x73,0x7B,0x6F,0x67,0x3E,0x00}, // 0
    {0x0C,0x0E,0x0F,0x0C,0x0C,0x0C,0x3F,0x00}, // 1
    {0x1E,0x33,0x30,0x1C,0x06,0x33,0x3F,0x00}, // 2
    {0x1E,0x33,0x30,0x1C,0x30,0x33,0x1E,0x00}, // 3
    {0x38,0x3C,0x36,0x33,0x7F,0x30,0x78,0x00}, // 4
    {0x3F,0x03,0x1F,0x30,0x30,0x33,0x1E,0x00}, // 5
    {0x1C,0x06,0x03,0x1F,0x33,0x33,0x1E,0x00}, // 6
    {0x3F,0x33,0x30,0x18,0x0C,0x0C,0x0C,0x00}, // 7
    {0x1E,0x33,0x33,0x1E,0x33,0x33,0x1E,0x00}, // 8
    {0x1E,0x33,0x33,0x3E,0x30,0x18,0x0E,0x00}, // 9
    {0x0C,0x1E,0x33,0x33,0x3F,0x33,0x33,0x00}, // A
    {0x3F,0x66,0x66,0x3E,0x66,0x66,0x3F,0x00}, // B
    {0x3C,0x66,0x03,0x03,0x03,0x66,0x3C,0x00}, // C
    {0x1F,0x36,0x66,0x66,0x66,0x36,0x1F,0x00}, // D
    {0x7F,0x46,0x16,0x1E,0x16,0x46,0x7F,0x00}, // E
    {0x7F,0x46,0x16,0x1E,0x16,0x06,0x0F,0x00}, // F
    {0x3C,0x66,0x03,0x03,0x73,0x66,0x7C,0x00}, // G
    {0x33,0x33,0x33,0x3F,0x33,0x33,0x33,0x00}, // H
    {0x1E,0x0C,0x0C,0x0C,0x0C,0x0C,0x1E,0x00}, // I
    {0x78,0x30,0x30,0x30,0x33,0x33,0x1E,0x00}, // J
    {0x67,0x66,0x36,0x1E,0x36,0x66,0x67,0x00}, // K
    {0x0F,0x06,0x06,0x06,0x46,0x66,0x7F,0x00}, // L
    {0x63,0x77,0x7F,0x7F,0x6B,0x63,0x63,0x00}, // M
    {0x63,0x67,0x6F,0x7B,0x73,0x63,0x63,0x00}, // N
    {0x1C,0x36,0x63,0x63,0x63,0x36,0x1C,0x00}, // O
    {0x3F,0x66,0x66,0x3E,0x06,0x06,0x0F,0x00}, // P
    {0x1E,0x33,0x33,0x33,0x3B,0x1E,0x38,0x00}, // Q
    {0x3F,0x66,0x66,0x3E,0x36,0x66,0x67,0x00}, // R
    {0x1E,0x33,0x07,0x0E,0x38,0x33,0x1E,0x00}, // S
    {0x3F,0x2D,0x0C,0x0C,0x0C,0x0C,0x1E,0x00}, // T
    {0x33,0x33,0x33,0x33,0x33,0x33,0x3F,0x00}, // U
    {0x33,0x33,0x33,0x33,0x33,0x1E,0x0C,0x00}, // V
    {0x63,0x63,0x63,0x6B,0x7F,0x77,0x63,0x00}, // W
    {0x63,0x63,0x36,0x1C,0x1C,0x36,0x63,0x00}, // X
    {0x33,0x33,0x33,0x1E,0x0C,0x0C,0x1E,0x00}, // Y
    {0x7F,0x63,0x31,0x18,0x4C,0x66,0x7F,0x00}, // Z
    {0x00,0x0C,0x0C,0x00,0x00,0x0C,0x0C,0x00}, // :
    {0x3C,0x0C,0x0C,0x0C,0x0C,0x0C,0x3C,0x00}, // [
    {0x3C,0x30,0x30,0x30,0x30,0x30,0x3C,0x00}  // ]
};

int indice_char(char c) {
    if (c >= '0' && c <= '9') return 1 + (c - '0');
    if (c >= 'A' && c <= 'Z') return 11 + (c - 'A');
    if (c >= 'a' && c <= 'z') return 11 + (c - 'a');
    if (c == ':') return 37;
    if (c == '[') return 38;
    if (c == ']') return 39;
    return 0; // Espaco
}

void desenhar_texto(const char* texto, int x, int y, int escala, Uint32 cor) {
    for (int i = 0; texto[i] != '\0'; i++) {
        int idx = indice_char(texto[i]);
        for (int linha = 0; linha < 8; linha++) {
            unsigned char bits = font8x8[idx][linha];
            for (int col = 0; col < 8; col++) {
                if (bits & (1 << col)) {
                    SDL_Rect px = {
                        x + (i * 8 * escala) + (col * escala),
                        y + (linha * escala),
                        escala,
                        escala
                    };
                    SDL_FillRect(screen, &px, cor);
                }
            }
        }
    }
}

void desenhar_hud() {
    Uint32 branco = SDL_MapRGB(screen->format, 255, 255, 255);
    Uint32 amarelo = SDL_MapRGB(screen->format, 255, 220, 50);
    Uint32 cinza = SDL_MapRGB(screen->format, 170, 170, 170);

    char linha_status[128];
    sprintf(linha_status, "HUNGER: %d   ENERGY: %d   LOVE: %d", fome, energia, love);
    desenhar_texto(linha_status, 20, 20, 2, branco);

    // Barrinhas visuais abaixo do texto de status
    SDL_Rect fundo_fome = { 20, 45, 100, 8 };
    SDL_Rect barra_fome = { 20, 45, fome, 8 };
    SDL_FillRect(screen, &fundo_fome, SDL_MapRGB(screen->format, 60, 20, 20));
    SDL_FillRect(screen, &barra_fome, SDL_MapRGB(screen->format, 230, 60, 60));

    SDL_Rect fundo_ener = { 180, 45, 100, 8 };
    SDL_Rect barra_ener = { 180, 45, energia, 8 };
    SDL_FillRect(screen, &fundo_ener, SDL_MapRGB(screen->format, 20, 60, 20));
    SDL_FillRect(screen, &barra_ener, SDL_MapRGB(screen->format, 60, 230, 60));

    // Menu de acoes na parte inferior da janela
    desenhar_texto("[1] BURGER  [2] CAKE  [3] PET", 20, 420, 2, amarelo);
    desenhar_texto("[4] SLEEP   [5] EXIT", 20, 445, 2, cinza);
}

// Desenha o sprite 64x64 ampliado (escala 4x -> 256x256)
void desenhar_ampliado(SDL_Surface* src, int quadro, int x_dst, int y_dst, int escala) {
    SDL_LockSurface(src);
    SDL_LockSurface(screen);

    Uint32* pixels_src = (Uint32*)src->pixels;
    Uint32* pixels_dst = (Uint32*)screen->pixels;
    int pitch_src = src->pitch / 4;
    int pitch_dst = screen->pitch / 4;
    int offset_x = quadro * 64;

    for (int y = 0; y < 64; y++) {
        for (int x = 0; x < 64; x++) {
            Uint32 cor = pixels_src[y * pitch_src + (offset_x + x)];
            if ((cor & src->format->Amask) == 0) continue; // Ignora fundo transparente

            for (int dy = 0; dy < escala; dy++) {
                for (int dx = 0; dx < escala; dx++) {
                    int px = x_dst + (x * escala) + dx;
                    int py = y_dst + (y * escala) + dy;
                    if (px >= 0 && px < screen->w && py >= 0 && py < screen->h) {
                        pixels_dst[py * pitch_dst + px] = cor;
                    }
                }
            }
        }
    }

    SDL_UnlockSurface(screen);
    SDL_UnlockSurface(src);
}

void loving();

SDL_Surface* carregar_sprite(unsigned char* dados, unsigned int tamanho) {
    SDL_RWops* rw = SDL_RWFromMem(dados, tamanho);
    SDL_Surface* temp = IMG_Load_RW(rw, 1);
    if (!temp) return NULL;
    SDL_Surface* otimizado = SDL_DisplayFormatAlpha(temp);
    SDL_FreeSurface(temp);
    return otimizado;
}

void animar_por(SDL_Surface* sheet, int duracao_ms, int progresso) {
    Uint32 inicio = SDL_GetTicks();
    int t_quadros = sheet->w / 64;
    if (t_quadros < 1) t_quadros = 1;

    int escala = 4;
    int pos_x = (640 - (64 * escala)) / 2;
    int pos_y = (480 - (64 * escala)) / 2 - 20;

    SDL_Event event;
    while (SDL_GetTicks() - inicio < (Uint32)duracao_ms && opcao == 1) {
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) opcao = 0;
        }

        int quadro = ((SDL_GetTicks() - inicio) / 95) % t_quadros;

        SDL_FillRect(screen, NULL, SDL_MapRGB(screen->format, 0, 0, 0));

        // Desenha o Tux ampliado em 4x
        desenhar_ampliado(sheet, quadro, pos_x, pos_y, escala);

        for (int i = 0; i < progresso; i++) {
            SDL_Rect barra = { 260 + (i * 45), 365, 35, 15 };
            SDL_FillRect(screen, &barra, SDL_MapRGB(screen->format, 0, 255, 0));
        }

        desenhar_hud(); // Desenha o texto e barras durante as animacoes
        SDL_Flip(screen);
        SDL_Delay(16);
    }
}

void atualizar_tempo() {
    time_t tempo_agora = time(NULL);
    double sec = difftime(tempo_agora, ultimo_tempo);

    if (sec >= 25.0) {
        int ciclos = (int)(sec / 25.0);

        fome += (ciclos * 5);
        energia -= (ciclos * 3);

        if (fome > 100) fome = 100;
        if (energia < 0) energia = 0;

        ultimo_tempo = tempo_agora;
    }
}

void loving() {
    love++;
    animar_por(spr_loving, 750, 0);
}

void eathamburguer() {
    love++;
    animar_por(spr_burger, 900, 1);
    animar_por(spr_burger, 900, 2);
    animar_por(spr_burger, 900, 3);
    fome = 0;
    loving();
}

void eatcake() {
    love++;
    animar_por(spr_cake, 900, 1);
    animar_por(spr_cake, 900, 2);
    animar_por(spr_cake, 900, 3);
    fome = 0;
    loving();
}

void tuxsleep() {
    animar_por(spr_normal, 900, 1);
    animar_por(spr_normal, 900, 2);
    animar_por(spr_normal, 900, 3);
    energia = 100;
    loving();
}

void menu() {
    atualizar_tempo();
	//define a escla de acordo com o tamanho da janela, a escala é 4 para poder ampliar as imagens e textos
    int escala = 4;
    int pos_x = (640 - (64 * escala)) / 2;
    int pos_y = (480 - (64 * escala)) / 2 - 20;

    SDL_FillRect(screen, NULL, SDL_MapRGB(screen->format, 0, 0, 0));
    desenhar_ampliado(spr_normal, 0, pos_x, pos_y, escala);

    desenhar_hud(); // Desenha os status e o menu na tela
    SDL_Flip(screen);

    SDL_Event event;
    while (SDL_PollEvent(&event)) {
        if (event.type == SDL_QUIT) opcao = 0;
        if (event.type == SDL_KEYDOWN) {
            switch (event.key.keysym.sym) {
                case SDLK_1: eathamburguer(); break;
                case SDLK_2: eatcake(); break;
                case SDLK_3: loving(); break;
                case SDLK_4: tuxsleep(); break;
                case SDLK_5: opcao = 0; break;
                default: break;
            }
        }
    }
    SDL_Delay(16);
}

int main(int argc, char* argv[]) {
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        fprintf(stderr, "Erro SDL: %s\n", SDL_GetError());
        return 1;
    }

    screen = SDL_SetVideoMode(640, 480, 32, SDL_SWSURFACE);
    if (!screen) {
        SDL_Quit();
        return 1;
    }
    SDL_WM_SetCaption("MyTux", NULL);
	
	spr_normal = carregar_sprite(normal_png, normal_png_len); //define oq cada variavel deve carregar  partir do sprits.h
    spr_loving = carregar_sprite(loving_sheet_png, loving_sheet_png_len);
    spr_burger = carregar_sprite(hamburguer_sheet_png, hamburguer_sheet_png_len);
    spr_cake   = carregar_sprite(cake_sheet_png, cake_sheet_png_len); 


    if (!spr_normal) spr_normal = spr_loving;
    if (!spr_burger) spr_burger = spr_loving;
    if (!spr_cake)   spr_cake   = spr_loving;


    ultimo_tempo = time(NULL);

    while (opcao == 1) {
        menu();
    }
	//define a logica de print para liberar a memoria
	if (spr_normal && spr_normal != spr_loving) SDL_FreeSurface(spr_normal);
	if (spr_burger && spr_burger != spr_loving) SDL_FreeSurface(spr_burger);
	if (spr_cake   && spr_cake   != spr_loving) SDL_FreeSurface(spr_cake);
	//limpa a memoria
	if (spr_loving) SDL_FreeSurface(spr_loving);
	//fecha o app
	SDL_Quit();
	return 0;
}
