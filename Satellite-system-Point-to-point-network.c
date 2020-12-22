#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){
	int GT=10; int BTP=80; int Lout=7,Lin=3,Outfdown=12400,Outfup=14700,Infdown=12850,Infup=14900,PSK;
	double FEC,alpha=0.3,Esat=36.0,Nsat=0.00,Rb2=2.0,Rb1=8.0,Lm=3.0;
	printf("Enter the PSK type \n");
	scanf("%d",&PSK);
	printf("Enter FEC value(2/3=0.66,3/4=0.75,4/5=0.8,5/6=0.83,6/7=0.86) \n");
	scanf("%lf",&FEC);
	 //Hub Berlin calculations//
	 double dberlin=38966.8,Lothberlin=0.9,Ltlberlin=5.0,Tberlin=290.0,NFberlin=8.0; //https://www.satbeams.com/footprints?beam=6143//
	//downlink link budget berlin//
	double fsplberlin=92.44177+(20*log10(Infdown))+(20*log10(dberlin));
	double bcdberlin=((1.0+alpha)*Rb2)/((FEC)*(log(PSK)/log(2)));
	int EIRPberlin=48; //https://www.satbeams.com/footprints?beam=6143//
	double EIRPberlindown=EIRPberlin-Lout-(10*log10(BTP/bcdberlin));
	double IRLdown=EIRPberlindown-fsplberlin-Lothberlin;
	printf("Enter the diameter of the antenna located in Berlin(unit=meter)\n");
	double Rberlin;
	scanf("%lf",&Rberlin);
	printf("Enter the antenna power of Hub in Berlin (unit=Watt) \n"); double Pberlin;
    scanf("%lf",&Pberlin);
	double Gdownberlin=17.8042+(20*log10(Infdown))+(20*log10(Rberlin));
	double RSLdown=IRLdown-Ltlberlin+Gdownberlin;
	double ebberlin=RSLdown-(10*log10(Rb2*1000000))+228.6-(10*log10(Tberlin))-NFberlin-Lm,db1=ebberlin/10.0;
	double ebberlin1=pow(10.0,db1);
	double ecberlin=(1.0/FEC)*ebberlin1;
	double kok=sqrt(ecberlin);
	double BERberlin=0.5*erfc(kok);
	printf("BER value of downlink link budget of HUB in Berlin=%lf\n",BERberlin);
    //uplink link budget berlin//
    double Gupberlin=17.8042+(20*log10(Outfup))+(20*log10(Rberlin));
    double PRFberlin=10*log10(Pberlin);
    double EIRPberlinup=PRFberlin-Ltlberlin+Gupberlin;
    double FSPLberlinup=92.44177+(20*log10(Outfup))+(20*log10(dberlin));
    double IRLberlinup=EIRPberlinup-FSPLberlinup-Lothberlin;
    double ebberlinup=IRLberlinup+(double)GT-Lin-(10*log10(Rb1*1000000))-Lm+228.6,db2=ebberlinup/10.0;
    double ebberlinup1=pow(10.0,db2);
    double ecberlinup1=(1.0/FEC)*ebberlinup1;
    double a=0.5*erfc(sqrt(ecberlinup1));  
    printf("BER value of uplink link budget of HUB in Berlin=%.10e\n\n",a);
    

     //Terminal Warsaw calculations//
	 double dwarsaw=38787.3,Lothwarsaw=0.3,Ltlwarsaw=2.0,Twarsaw=290.0,NFwarsaw=3.0; //https://www.satbeams.com/footprints?beam=6143//
	//downlink link budget warsaw//
	double fsplwarsaw=92.44177+(20*log10(Outfdown))+(20*log10(dwarsaw));
	double bcdwarsaw=((1.0+alpha)*Rb1)/((FEC)*(log(PSK)/log(2)));
	int EIRPwarsaw=47;//https://www.satbeams.com/footprints?beam=6143//
	double EIRPwarsawdown=EIRPwarsaw-Lout-(10*log10(BTP/bcdwarsaw));
	double IRLdownwarsaw=EIRPwarsawdown-fsplwarsaw-Lothwarsaw;
	printf("Enter the diameter of the antenna located in Warsaw(unit=meter)\n");
	double Rwarsaw;
	scanf("%lf",&Rwarsaw);
	printf("Enter the antenna power of terminal in Warsaw (unit=Watt) \n"); double Pwarsaw;
    scanf("%lf",&Pwarsaw);
	double Gdownwarsaw=17.8042+(20*log10(Outfdown))+(20*log10(Rwarsaw));
	double RSLdownwarsaw=IRLdownwarsaw-Ltlwarsaw+Gdownwarsaw;
	double ebberwarsaw=RSLdownwarsaw-(10*log10(Rb1*1000000))+228.6-(10*log10(Twarsaw))-NFwarsaw-Lm,db11=ebberwarsaw/10.0;
	double ebberwarsaw1=pow(10.0,db11);
	double ecberwarsaw=(1.0/FEC)*ebberwarsaw1;
	double kokwarsaw1=sqrt(ecberwarsaw);
	double BERwarsaw1=0.5*erfc(kokwarsaw1);
	printf("BER value of downlink link budget of terminal in Warsaw=%lf\n",BERwarsaw1);
    //uplink link budget warsaw//
    double Gupwarsaw=17.8042+(20*log10(Infup))+(20*log10(Rwarsaw));
    double PRFwarsaw=10*log10(Pwarsaw);
    double EIRPwarsawup=PRFwarsaw-Ltlwarsaw+Gupwarsaw;
    double FSPLwarsawup=92.44177+(20*log10(Infup))+(20*log10(dwarsaw));
    double IRLwarsawup=EIRPwarsawup-FSPLwarsawup-Lothwarsaw;
    double ebwarsawup=IRLwarsawup+(double)GT-Lin-(10*log10(Rb2*1000000))-Lm+228.6,db22=ebwarsawup/10.0;
    double ebwarsawup1=pow(10.0,db22);
    double ecwarsawup1=(1.0/FEC)*ebwarsawup1;
    double awarsaw=0.5*erfc(sqrt(ecwarsawup1));  
    printf("BER value of uplink link budget of terminal in Warsaw=%.10e\n\n",awarsaw);
    
    
     //Terminal barcelona calculations//
	 double dbarcelona=38513.7,Lothbarcelona=0.5,Ltlbarcelona=1.0,Tbarcelona=292.0,NFbarcelona=4.0; //https://www.satbeams.com/footprints?beam=6143//
	//downlink link budget barcelona//
	double fsplbarcelona=92.44177+(20*log10(Outfdown))+(20*log10(dbarcelona));
	double bcdbarcelona=((1.0+alpha)*Rb1)/((FEC)*(log(PSK)/log(2)));
	int EIRPbarcelona=48;//https://www.satbeams.com/footprints?beam=6143//
	double EIRPbarcelonadown=EIRPbarcelona-Lout-(10*log10(BTP/bcdbarcelona));
	double IRLdownbarcelona=EIRPbarcelonadown-fsplbarcelona-Lothbarcelona;
	printf("Enter the diameter of the antenna located in Barcelona(unit=meter)\n");
	double Rbarcelona;
	scanf("%lf",&Rbarcelona);
	printf("Enter the antenna power of terminal in Barcelona (unit=Watt) \n"); double Pbarcelona;
    scanf("%lf",&Pbarcelona);
	double Gdownbarcelona=17.8042+(20*log10(Outfdown))+(20*log10(Rbarcelona));
	double RSLdownbarcelona=IRLdownbarcelona-Ltlbarcelona+Gdownbarcelona;
	double ebberbarcelona=RSLdownbarcelona-(10*log10(Rb1*1000000))+228.6-(10*log10(Tbarcelona))-NFbarcelona-Lm,db111=ebberbarcelona/10.0;
	double ebberbarcelona1=pow(10.0,db111);
	double ecberbarcelona=(1.0/FEC)*ebberbarcelona1;
	double kokbarcelona1=sqrt(ecberbarcelona);
	double BERbarcelona1=0.5*erfc(kokbarcelona1);
	printf("BER value of downlink link budget of terminal in Barcelona=%lf\n",BERbarcelona1);
    //uplink link budget barcelona//
    double Gupbarcelona=17.8042+(20*log10(Infup))+(20*log10(Rbarcelona));
    double PRFbarcelona=10*log10(Pbarcelona);
    double EIRPbarcelonaup=PRFbarcelona-Ltlbarcelona+Gupbarcelona;
    double FSPLbarcelonaup=92.44177+(20*log10(Infup))+(20*log10(dbarcelona));
    double IRLbarcelonaup=EIRPbarcelonaup-FSPLbarcelonaup-Lothbarcelona;
    double ebbarcelonaup=IRLbarcelonaup+(double)GT-Lin-(10*log10(Rb2*1000000))-Lm+228.6,db222=ebbarcelonaup/10.0;
    double ebbarcelonaup1=pow(10.0,db222);
    double ecbarcelonaup1=(1.0/FEC)*ebbarcelonaup1;
    double abarcelona=0.5*erfc(sqrt(ecbarcelonaup1));  
    printf("BER value of uplink link budget of terminal in Barcelona=%.10e\n\n",abarcelona);
    
    //Terminal Athens calculations//
	 double dathens=37545.5,Lothathens=0.7,Ltlathens=1.0,Tathens=292.0,NFathens=5.0; //https://www.satbeams.com/footprints?beam=6143//
	//downlink link budget athens//
	double fsplathens=92.44177+(20*log10(Outfdown))+(20*log10(dathens));
	double bcdathens=((1.0+alpha)*Rb1)/((FEC)*(log(PSK)/log(2)));
	int EIRPathens=46;//https://www.satbeams.com/footprints?beam=6143//
	double EIRPathensdown=EIRPathens-Lout-(10*log10(BTP/bcdathens));
	double IRLdownathens=EIRPathensdown-fsplathens-Lothathens;
	printf("Enter the diameter of the antenna located in Athens(unit=meter)\n");
	double Rathens;
	scanf("%lf",&Rathens);
	printf("Enter the antenna power of terminal in Athens (unit=Watt) \n"); double Pathens;
    scanf("%lf",&Pathens);
	double Gdownathens=17.8042+(20*log10(Outfdown))+(20*log10(Rathens));
	double RSLdownathens=IRLdownathens-Ltlathens+Gdownathens;
	double ebberathens=RSLdownathens-(10*log10(Rb1*1000000))+228.6-(10*log10(Tathens))-NFathens-Lm,db1111=ebberathens/10.0;
	double ebberathens1=pow(10.0,db1111);
	double ecberathens=(1.0/FEC)*ebberathens1;
	double kokathens1=sqrt(ecberathens);
	double BERathens1=0.5*erfc(kokathens1);
	printf("BER value of downlink link budget of terminal in Athens=%lf\n",BERathens1);
    //uplink link budget Athens//
    double Gupathens=17.8042+(20*log10(Infup))+(20*log10(Rathens));
    double PRFathens=10*log10(Pathens);
    double EIRPathensup=PRFathens-Ltlathens+Gupathens;
    double FSPLathensup=92.44177+(20*log10(Infup))+(20*log10(dathens));
    double IRLathensup=EIRPathensup-FSPLathensup-Lothathens;
    double ebathensup=IRLathensup+(double)GT-Lin-(10*log10(Rb2*1000000))-Lm+228.6,db2222=ebathensup/10.0;
    double ebathensup1=pow(10.0,db2222);
    double ecathensup1=(1.0/FEC)*ebathensup1;
    double aathens=0.5*erfc(sqrt(ecathensup1));  
    printf("BER value of uplink link budget of terminal in Athens=%.10e\n\n",aathens);
    	
		return 0;
}
