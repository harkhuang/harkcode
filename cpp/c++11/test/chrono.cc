


/* Introduce to <chrono> 
	
	-- A precision-neutral library for time and date
	
 * clocks:
 *
 * std::chrono::system_clock:  current time according to the system (it is not steady)
 * std::chrono::steady_clock:  goes at a uniform rate (it can't be adjusted)
 * std::chrono::high_resolution_clock: provides smallest possible tick period. 
 *                   (might be a typedef of steady_clock or system_clock)
 *
 * clock period is represented with std:ratio<>
 */

std::ratio<1,10>  r; // 
cout << r.num << "/" << r.den << endl;

cout << chrono::system_clock::period::num << "/" << chrono::system_clock::period::den << endl;
cout << chrono::steady_clock::period::num << "/" << chrono::steady_clock::period::den << endl;
cout << chrono::high_resolution_clock::period::num << "/" << chrono::high_resolution_clock::period::den << endl;

/*
 *
 * std:chrono::duration<>:  represents time duration
 *    duration<int, ratio<1,1>> --  number of seconds stored in a int  (this is the default)
 *    duration<double, ration<60,1>> -- number of minutes (60 seconds) stored in a double
 *    convenince duration typedefs in the library:
 *    nanoseconds, microseconds, milliseconds, seconds, minutes, hours
 * system_clock::duration  -- duration<T, system_clock::period>
 *                                 T is a signed arithmetic type, could be int or long or others
 */
chrono::microseconds mi(2745);
chrono::nanoseconds na = mi;
chrono::milliseconds mill = chrono::duration_cast<chrono::milliseconds>(mi);  // when information loss could happen, convert explicitly
														  // Truncation instead of rounding
	mi = mill + mi;  // 2000 + 2745 = 4745
	mill = chrono::duration_cast<chrono::milliseconds>(mill + mi);  // 6
	cout << na.count() << std::endl;
	cout << mill.count() << std::endl;
	cout << mi.count() << std::endl;

   cout << "min: " << chrono::system_clock::duration::min().count() << "\n";
   cout << "max: " << chrono::system_clock::duration::max().count() << "\n";


 /* std::chrono::time_point<>: represents a point of time
 *       -- Length of time elapsed since a spacific time in history: 
 *          00:00 January 1, 1970 (Corordinated Universal Time - UTC)  -- epoch of a clock
 * time_point<system_clock, milliseconds>:  according to system_clock, the elapsed time since epoch in milliseconds
 *
 * typdefs
  system_clock::time_point  -- time_point<system_clock, system_clock::duration>
  steady_clock::time_point  -- time_point<steady_clock, steady_clock::duration>
 */
	// Use system_clock
	chrono::system_clock::time_point tp = chrono::system_clock::now();
	cout << tp.time_since_epoch().count() << endl;  
	tp = tp + seconds(2);  // no need for cast because tp is very high resolution
	cout << tp.time_since_epoch().count() << endl;

	// Calculate time interval
	chrono::steady_clock::time_point start = chrono::steady_clock::now();
	cout << "I am bored" << endl;
	chrono::steady_clock::time_point end = chrono::steady_clock::now();
	chrono::steady_clock::duration d = end - start;
	if (d == chrono::steady_clock::duration::zero())
		cout << "no time elapsed" << endl;
	cout << duration_cast<microseconds>(d).count() << endl;
   // Using system_clock may result in incorrect value

