with Ada.Text_IO;
use Ada.Text_IO;

with Ada.Text_IO, Calendar;
use Ada.Text_IO, Calendar;

procedure source is

X_initial : FLOAT := 0.0;
M         : FLOAT := 1.0;
A         : FLOAT := 7.0;
C         : FLOAT := 13.0 / 31.0;


procedure Set_Seed is
   Time_And_Date    : TIME;
   All_Day          : DAY_DURATION;
   Minutes          : FLOAT;
   Int_Minutes      : INTEGER;
   Part_Of_A_Minute : FLOAT;
begin
   Time_And_Date := Clock;                -- Get the time and date
   All_Day := Seconds(Time_And_Date);     -- Seconds since midnight
   Minutes := FLOAT(All_Day) / 60.0;   -- Floating type Minutes
   Int_Minutes := INTEGER(Minutes - 0.5); -- Integer type minutes
   Part_Of_A_Minute := FLOAT(All_Day)
                               - 60.0 * FLOAT(Int_Minutes);
   X_Initial := 0.1;
end Set_Seed;


procedure Force_Seed(Start_Seed : FLOAT) is
Temp : FLOAT;
Natural_Temp : NATURAL;
begin
   Natural_Temp := NATURAL(Start_Seed - 0.5);
   Temp := Start_Seed - FLOAT(Natural_Temp);
   X_Initial := Start_Seed;
exception
   when Constraint_Error =>
      Put_Line("Seed out of range, ignored");
end Force_Seed;


function Get_Seed return FLOAT is
begin
   return X_Initial;
end Get_Seed;


function Random_Number return FLOAT is
   Temp         : FLOAT;
   Natural_Temp : NATURAL;
begin
   Temp := A * X_Initial + C;
   Natural_Temp := NATURAL(Temp - 0.5);
   Temp := Temp - FLOAT(Natural_Temp);
   X_Initial := Temp;
   return Temp;
end Random_Number;

--procedure TestRan is

--   package My_Random is new Random(FLOAT);
--   use My_Random;

   package Int_IO is new Ada.Text_IO.Integer_IO(INTEGER);
   use Int_IO;
   package Flt_IO is new Ada.Text_IO.Float_IO(FLOAT);
   use Flt_IO;

   SIZE : constant := 100;
   type MY_ARRAY is array(1..SIZE) of INTEGER;
   Events   : MY_ARRAY;
   Int_Rand : INTEGER;

begin
   Set_Seed;
   for Index in 1..2 loop
      Put(Random_Number, 2, 6, 0);
   end loop;

end source;

