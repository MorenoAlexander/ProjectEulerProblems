/******************************************************************************

You are given the following information, but you may prefer to do some research for yourself.

1 Jan 1900 was a Monday.
Thirty days has September,
April, June and November.
All the rest have thirty-one,
Saving February alone,
Which has twenty-eight, rain or shine.
And on leap years, twenty-nine.
A leap year occurs on any year evenly divisible by 4, but not on a century unless it is divisible by 400.
How many Sundays fell on the first of the month during the twentieth century (1 Jan 1901 to 31 Dec 2000)?



After coding results, the code "as-is", actually gets us the correct Answer(171+1), likely because we do not account for the extra day in february thanks to the leap year.
*******************************************************************************/
public class PE19
{
    private static boolean isLeapYear(int year){
        if( year % 4 == 0 ){
            return true;
        }
        return false;
    }
    
    public static int calcforMonth(int m,int  days){
        		int[] monthLength = {31,28,31,30,
		                     31,30,31,31,
		                     30,31,30,31};
        
        for(int j = 0;j<m+1;j++){
            days-= monthLength[j];
        }
        return days;
    }
    
    
	public static void main(String[] args) {
		String[] months ={"January","February","March","April",
		                 "May","June","July","August",
		                 "September","October","November","December"};
		String[] days = {"Sunday","Monday","Tuesday","Wednesday","Thursday","Friday","Saturday"};
		int[] monthLength = {31,28,31,30,
		                     31,30,31,31,
		                     30,31,30,31};
		int yearCount = 1901;
		int currentMonth = 0;
		int currentDay = 1;
		int dayCount = 1;
		int sundays = 0;
		
		
		//Each year
		for(yearCount = 1901;yearCount<2001;yearCount++){
		    dayCount=0;
		    //Is a leap year!
		    if(isLeapYear(yearCount)){
		        for(int m = 0;m<12;m++){
		            dayCount+= monthLength[m];
		            for(int d = 0;d<monthLength[m];d++){
		                currentDay+=1;
		                if(currentDay==7){
		                    currentDay=0;
		                }
		            }
		            
		            System.out.println(calcforMonth(m,dayCount));
		            if(days[currentDay]=="Sunday" && calcforMonth(m,dayCount) == 0){
		                sundays++;
		            }
		        }
		        
		    }
		    
		    
		    //Not a leap year!
		    else{
		        for(int m = 0;m<12;m++){
		            dayCount+= monthLength[m];
		            for(int d = 0;d<monthLength[m];d++){
		                currentDay+=1;
		                if(currentDay==7){
		                    currentDay=0;
		                }
		            }
		            
		            System.out.println(calcforMonth(m,dayCount));
		            if(days[currentDay]=="Sunday"){
		                sundays++;
		            }
		        }
		    }
		}
		System.out.println("Sundays: "+ sundays);
		System.out.print("Year: "+ yearCount);
	}
	
        
}
