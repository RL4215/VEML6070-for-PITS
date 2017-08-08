// Types

typedef enum {fmIdle, fmLaunched, fmBurst, fmDescending, fmLanding, fmLanded} TFlightMode;

struct TGPS
{
	// GPS
	long SecondsInDay;					// Time in seconds since midnight
	int Hours, Minutes, Seconds;
	float Longitude, Latitude;
	int32_t Altitude;
	unsigned int Satellites;
	int Speed;
	int Direction;
	
	// Calculated from GPS
	int32_t MaximumAltitude, MinimumAltitude;
	float AscentRate;
	
	// Sensors
	float DS18B20Temperature[2];
	float BatteryVoltage;
	float BMP180Temperature;
	float Humidity;
	float Pressure;
	float BoardCurrent;
	int DS18B20Count;
	float UV_data;

	// Flight control
	TFlightMode FlightMode;
	
	// Prediction
	float PredictedLongitude, PredictedLatitude;
	float PredictedLandingSpeed;
	int TimeTillLanding;
	float CDA;
		
	// int FlightMode;
	// int PowerMode;
	// int Lock;
	unsigned int MessageCount;

#	ifdef EXTRAS_PRESENT
#		include "ex_gps.h"
#	endif		
};


// functions

void *GPSLoop(void *some_void_ptr);


#ifdef EXTRAS_PRESENT
void gps_postprocess_position(struct TGPS *GPS, int ActionMask, float latitude, float longitude);
#endif	

