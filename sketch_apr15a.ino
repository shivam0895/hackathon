

#include <SPI.h>


#include <Ethernet.h>










byte mac[] = { 0x00, 0xAA, 0xBB, 0xCC, 0xDE, 0x02 };


byte ip[] = { 192, 168, 0, 100 }; 


byte gateway[] = { 192, 168, 0, 1 }; 


byte subnet[] = { 255, 255, 255, 0 };

EthernetServer server(80); 

String readString;


void setup()


{  




  pinMode(6, OUTPUT); 


  pinMode(7, OUTPUT);




  Ethernet.begin(mac, ip, gateway, subnet);


  server.begin();


  Serial.begin(9600);


  Serial.println("server LED test 1.0");

}




void loop()


{  



  EthernetClient client = server.available();


  if (client) {


    while (client.connected()) {


      if (client.available()) {


        char c = client.read();



        if (readString.length() < 100) {



          readString += c;


        }


        if (c == '\n') {


          Serial.println(readString); 

          client.println("HTTP/1.1 200 OK");

          client.println("Content-Type: text/html");

          client.println();


          client.println("<HTML>");


          client.println("<HEAD>");


          client.println("<meta name='apple-mobile-web-app-capable' content='yes' />");


          client.println("<meta name='apple-mobile-web-app-status-bar-style' content='black-translucent' />");


          client.println("<link rel=\"stylesheet\" type=\"text/css\" href=\"http://arduino-autohome.googlecode.com/svn/trunk/autohome.css\" />");


          client.println("</HEAD>");


          client.println("<body bgcolor=\"#D0D0D0\">");
          

          client.println("<hr/>");


          client.println("<hr/>");

          client.println("<h4><center> HOME AUTOMATION </center></h4>");


          client.println("<hr/>");


          client.println("<hr/>");


          


          client.println("<br />");


          client.println("<br />");


          client.println("<br />");


          client.println("<br />");


          client.println("<br />");


          client.println("<a href=\"/?relay1on\"\">Turn On Bulb</a>");


          client.println("<a href=\"/?relay1off\"\">Turn Off Bulb</a><br />"); 


          client.println("<br />");


          client.println("<br />");


          client.println("<br />");


          client.println("<br />");

           client.println("<a href=\"/?relay2on\"\">Turn On LED</a>");


          client.println("<a href=\"/?relay2off\"\">Turn Off LED</a><br />");
          client.println("<br />");


          client.println("<br />");


          client.println("<br />");


          client.println("<br />");




          if(readString.indexOf("?relay1on") >0)

          {


            digitalWrite(6, HIGH);


            Serial.println("Led On");


            client.println("<link rel='apple-touch-icon' href='http://chriscosma.co.cc/on.png' />");


            client.println("<br />");


        }


          else{


          if(readString.indexOf("?relay1off") >0)
          {


            digitalWrite(6, LOW);


            Serial.println("Led Off");


            client.println("<link rel='apple-touch-icon' href='http://chriscosma.co.cc/off.png' />");



            client.println("<br />");


        }


          }
           


          if(readString.indexOf("?relay2on") >0)

          {


            digitalWrite(7, HIGH);

            Serial.println("Led On");


            client.println("<link rel='apple-touch-icon' href='http://chriscosma.co.cc/on.png' />");



            client.println("<br />");


          }


          else{


          if(readString.indexOf("?relay2off") >0)

          {


            digitalWrite(7, LOW);

            Serial.println("Led Off");


            client.println("<link rel='apple-touch-icon' href='http://chriscosma.co.cc/off.png' />");



            client.println("<br />");


          }


          }



          client.println("<center>");


          client.println("<table border=\"5\">");


          client.println("<tr>");


          


          if (digitalRead(6))


          { 


           client.print("<td>Bulb is ON</td>");


           


          }


          else


          {


            client.print("<td>Bulb is OFF</td>");


           


          }


          


          


          

          client.println("<br />");


          


          if (digitalRead(7))


          { 


           client.print("<td>LED is ON</td>");


           


          }


          else


          {


            client.print("<td>LED is OFF</td>");


            


          }


          


          client.println("</tr>");


          client.println("<tr>");




          


          client.println("</tr>");


          client.println("</table>");


          


          client.println("</center>");


          


          


          


          //clearing string for next read


          


          readString="";




          client.println("</body>");


          client.println("</HTML>");




          delay(1);


          client.stop();




        }


      }


    }


  }


}

