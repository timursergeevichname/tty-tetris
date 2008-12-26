/*
 *      tetris.h
 *      Copyright © 2008 Martin Duquesnoy <xorg62@gmail.com>
 *      All rights reserved.
 *
 *      Redistribution and use in source and binary forms, with or without
 *      modification, are permitted provided that the following conditions are
 *      met:
 *
 *      * Redistributions of source code must retain the above copyright
 *        notice, this list of conditions and the following disclaimer.
 *      * Redistributions in binary form must reproduce the above
 *        copyright notice, this list of conditions and the following disclaimer
 *        in the documentation and/or other materials provided with the
 *        distribution.
 *      * Neither the name of the  nor the names of its
 *        contributors may be used to endorse or promote products derived from
 *        this software without specific prior written permission.
 *
 *      THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 *      "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 *      LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
 *      A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
 *      OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 *      SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 *      LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 *      DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 *      THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 *      (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 *      OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

/* Libs */
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

/* Expension factor of shapes */
#define EXP_FACT 2

/* Frame dimension */
#define FRAMEW 23
#define FRAMEH 23
#define FRAMEW_NB 14
#define FRAMEH_NB 6

/* Generate Random number */
#define RAND(m, M) ((rand() % (M - m + 1)) + m)

#define N_POS ((current.pos < 3) ? current.pos + 1 : 0)
#define P_POS ((current.pos > 0) ? current.pos - 1 : 3)

/* Draw the score.. */
#define DRAW_SCORE() set_color(Score);                             \
     printf("\033[%d;%dH %d",FRAMEH_NB + 3, FRAMEW + 10, score);   \
     printf("\033[%d;%dH %d",FRAMEH_NB + 4, FRAMEW + 10, lines);   \
     set_color(0);

/* Bool type */
typedef enum { False, True } Bool;

/* Shape structure */
struct shape_t
{
     int num;
     int next;
     int pos;
     int x, y;
} current;

/* Color enum */
enum { Black, Blue, Red, Magenta, White, Green, Cyan, Yellow, Border, Score, ColLast };

/* Prototypes */

/* util.c */
int getch(void);
void printxy(int, int, char*);
void set_color(int);

/* frame.c */
void frame_init(void);
void frame_nextbox_init(void);
void frame_refresh(void);
void frame_nextbox_refresh(void);

/* shapes.c */
void shape_set(void);
void shape_unset(void);
void shape_new(void);
void shape_go_down(void);
void shape_set_position(int);
void shape_move(int);
void shape_drop(void);

/* tetris.c */
void check_plain_line(void);
int check_possible_pos(int, int);

/* Variables */

/* Frame data */
const int shapes[7][4][4][2];
int frame[FRAMEH + 1][FRAMEW + 1];
int frame_nextbox[FRAMEH][FRAMEW];
int score;
int lines;
Bool running;
