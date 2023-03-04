#include <iostream>
#include <allegro.h>
///
    int Score_Left = 0,Score_Right = 0;
///
///----------------------------------------------------------------------///
    float circle_x = 400,circle_y = 200,x_speed = 0.6,y_speed = 0.6; /// Kreis
///----------------------------------------------------------------------///
    float x1=780, y1 =150,x2=800, y2 =250; /// Rechteck rechts
    //                                          (x1|y1)///////////
                                                //              //
                                                //              //
                                                //              //
                                                //              //
                                                //              //
                                                ////////////(x2|y2)
///----------------------------------------------------------------------///
    float x3=0, y3 =150,x4=20, y4 =250;   /// Rechteck links
    //                                          (x3|y3)///////////
                                                //              //
                                                //              //
                                                //              //
                                                //              //
                                                //              //
                                                ////////////(x4|y4)

using namespace std;


///Functions
void Set_UP_allegro();

void startscreen();

float draw();

void collision();
///_____________________________________________________________
int main()
{
    Set_UP_allegro();
    startscreen();


while(key[KEY_ESC]==0)
{
    draw();
}

    return 0;
}
END_OF_MAIN()
///______________________________________________________________
void Set_UP_allegro()
{
    allegro_init();
    install_keyboard();
    install_timer();

    set_color_depth(32);
    set_gfx_mode(GFX_AUTODETECT_WINDOWED,800,400,0,0);
    clear_to_color(screen, makecol(0,0,0));

}
///_______________________________________________________________
void startscreen()
{
    float rect_speed=2;
 while(key[KEY_SPACE]==0)
 {
    BITMAP * Buffer = create_bitmap(800,400);

    textout_ex(Buffer,font,"Allegro 4 PONG!",350,100,makecol(255,255,255),-1);

    textout_ex(Buffer,font,"Press SPACE to start the Game!",300,300,makecol(255,255,255),-1);


    textout_ex(Buffer,font,"PLAYER LEFT",100,50,makecol(255,255,255),-1);

    textout_ex(Buffer,font,"W = UP",100,100,makecol(255,255,255),-1);

    textout_ex(Buffer,font,"S = DOWN",100,300,makecol(255,255,255),-1);


    textout_ex(Buffer,font,"PLAYER Right",600,50,makecol(255,255,255),-1);

    textout_ex(Buffer,font,"I = UP",600,100,makecol(255,255,255),-1);

    textout_ex(Buffer,font,"K = DOWN",600,300,makecol(255,255,255),-1);


    circlefill(Buffer,circle_x,circle_y,10,makecol(0,100,0));

    rectfill(Buffer, x1,y1,x2,y2,makecol(0,255,0));///left

    rectfill(Buffer, x3,y3,x4,y4,makecol(0,255,0));///right





    if(key[KEY_I])
    {
      rectfill(Buffer, x1,y1,x2,y2,makecol(0,255,0));///left

      y1 = y1 - rect_speed;
      y2 = y2 - rect_speed;

      if(y1 < 0)
      {
          y1 =0;
          y2 =100;
      }


    }
    if(key[KEY_K])
    {
      rectfill(Buffer, x1,y1,x2,y2,makecol(0,255,0));///left
      y1 = y1 + rect_speed;
      y2 = y2 + rect_speed;
      if(y2 > SCREEN_H)
      {
          y1 = 300;
          y2 = SCREEN_H;
      }

    }
    if(key[KEY_W])
    {
      rectfill(Buffer, x3,y3,x4,y4,makecol(0,255,0));///right
      y3 = y3 - rect_speed;
      y4 = y4 - rect_speed;
      if(y3 < 0)
      {
          y3=0;
          y4=100;
      }

    }
    if(key[KEY_S])
    {
      rectfill(Buffer, x3,y3,x4,y4,makecol(0,255,0));///right
      y3 = y3 + rect_speed;
      y4 = y4 + rect_speed;
      if(y4 > SCREEN_H)
      {
          y3=300;
          y4=SCREEN_H;
      }

    }
    blit(Buffer,screen,0,0,0,0,800,400);
    destroy_bitmap(Buffer);
 }
    clear_to_color(screen, makecol(0,0,0));

}
///------------------------------------------------------------------
float draw()
{

        BITMAP * Buffer = create_bitmap(800,400);

        line(Buffer,400,0,400,400,makecol(255,255,255));
        circlefill(Buffer,circle_x,circle_y,10,makecol(0,100,0));
        rectfill(Buffer, x1,y1,x2,y2,makecol(0,255,0));///Rechts
        rectfill(Buffer, x3,y3,x4,y4,makecol(0,255,0));///Links

        circlefill(Buffer,circle_x,circle_y,10,makecol(0,100,0));
        circle_x = circle_x + x_speed;
        circle_y = circle_y + y_speed;


        if(circle_y < 0 || circle_y > SCREEN_H)
        {
            y_speed = y_speed * (-1);
        }

        if(circle_x < 0 ) ///Linkes Seitenout
        {
            circle_x = 400;
            ++Score_Left; cout << "\n Score Links: " <<Score_Left;
            rest(1000);
        }


         if(circle_x > SCREEN_W ) /// Rechtes Seitenout
        {
            circle_x = 400;
            ++Score_Right; cout <<"\n Score Rechts:" <<Score_Right;
            rest(1000);

        }
 ///-----------------------------------------------------------------------
        if(Score_Left == 10)
        {
        allegro_message("Spieler Rechts hat gewonnen");
        //textout(Buffer,font,"Links hat gewonnen",20,20,makecol(255,0,0));
        }
                                                                            ///Gewinner bestimmen
        if(Score_Right == 10)
        {
        allegro_message("Spieler Links hat gewonnen");
        //textout(Buffer,font,"Rechts hat gewonnen",560,20,makecol(255,0,0));
        }
///------------------------------------------------------------------------
        float rect_speed = 1.5;
        if(key[KEY_I])
        {
            rectfill(Buffer, x1,y1,x2,y2,makecol(0,255,0));
            y1-=rect_speed;
            y2-=rect_speed;
            if(y1<0)
            {
                y1=0;
                y2=100;
            }
        }
         if(key[KEY_K])
        {
            rectfill(Buffer, x1,y1,x2,y2,makecol(0,255,0));
            y1+=rect_speed;
            y2+=rect_speed;
            if(y2>SCREEN_H)
            {
                y1=300;
                y2=SCREEN_H;
            }
        }
        if(key[KEY_W])
        {
            rectfill(Buffer, x3,y3,x4,y4,makecol(0,255,0));
            y3-=rect_speed;
            y4-=rect_speed;
            if(y3<0)
            {
                y3=0;
                y4=100;
            }
        }
         if(key[KEY_S])
        {
            rectfill(Buffer, x3,y3,x4,y4,makecol(0,255,0));
            y3+=rect_speed;
            y4+=rect_speed;
            if(y4>SCREEN_H)
            {
                y3=300;
                y4=SCREEN_H;
            }
        }
        collision();



        blit(Buffer,screen,0,0,0,0,800,400);
        destroy_bitmap(Buffer);




}
///_______________________________________________________________
void collision()
{


    ///-------------------------------------------------------
    if(circle_x > x1 && circle_x < x2)
    {
        if(circle_y > y1 && circle_y < y2)
        {
            //cout << "Collision Rechts";                            ///Collision Rechte Seite
            x_speed *= (-1);


        }
    }

    ///--------------------------------------------------------

    if(circle_x < x4 && circle_x > x3)
    {
        if(circle_y > y3 && circle_y < y4)
        {
            //cout << "Collision Links";                             ///Collision Links Seite
            x_speed *= (-1);



        }
    }
}
