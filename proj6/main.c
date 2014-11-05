#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "circular.h"

void run_main_a();
void run_main_b();
void run_main_c();

int main(int argc, const char * argv[]) {
    
    printf("========== Running Main A ==========\n");
    run_main_a();
    printf("====================================\n");
    
    printf("========== Running Main B ==========\n");
    run_main_b();
    printf("====================================\n");
    
    printf("========== Running Main C ==========\n");
    run_main_c();
    printf("====================================\n");
    
    return 0;
}

void run_main_a() {
    cbuf *cb1 ;
    
    cb1 = cbuf_init() ;
    cbuf_update(cb1, 60, 1.291) ;
    cbuf_update(cb1, 63, 1.287) ;
    cbuf_update(cb1, 63, 1.231) ;
    cbuf_update(cb1, 69, 1.229) ;
    cbuf_update(cb1, 72, 1.247) ;
    
    cbuf_dump(cb1) ;
    
    cbuf_update(cb1, 361, 1.291) ;
    
    cbuf_dump(cb1) ;
    
    cbuf_update(cb1, 411, 1.291) ;
    cbuf_update(cb1, 412, 1.281) ;
    cbuf_update(cb1, 413, 1.292) ;
    cbuf_update(cb1, 414, 1.284) ;
    cbuf_update(cb1, 414, 1.290) ;
    
    cbuf_dump(cb1) ;
    
    cbuf_update(cb1, 511, 1.241) ;
    cbuf_update(cb1, 512, 1.251) ;
    cbuf_update(cb1, 513, 1.232) ;
    cbuf_update(cb1, 514, 1.202) ;
    cbuf_update(cb1, 517, 1.119) ;
    
    cbuf_dump(cb1) ;
    
    cbuf_update(cb1, 551, 1.080) ;
    cbuf_update(cb1, 552, 1.081) ;
    cbuf_update(cb1, 553, 1.079) ;
    cbuf_update(cb1, 554, 1.088) ;
    cbuf_update(cb1, 561, 1.072) ;
    cbuf_update(cb1, 562, 1.113) ;
    cbuf_update(cb1, 563, 1.091) ;
    cbuf_update(cb1, 564, 1.092) ;
    cbuf_update(cb1, 571, 1.089) ;
    cbuf_update(cb1, 572, 1.073) ;
    cbuf_update(cb1, 573, 1.061) ;
    cbuf_update(cb1, 574, 1.111) ;
    cbuf_update(cb1, 581, 1.119) ;
    cbuf_update(cb1, 582, 1.123) ;
    cbuf_update(cb1, 583, 1.151) ;
    cbuf_update(cb1, 584, 1.153) ;
    
    cbuf_dump(cb1) ;
    
    cbuf_update(cb1, 750, 1.200) ;
    cbuf_dump(cb1) ;
    
    cbuf_update(cb1, 818, 1.210) ;
    cbuf_dump(cb1) ;
    
    cbuf_update(cb1, 868, 1.230) ;
    cbuf_dump(cb1) ;
    
    cbuf_update(cb1, 878, 1.230) ;
    cbuf_dump(cb1) ;
    
    cbuf_update(cb1, 900, 1.240) ;
    cbuf_dump(cb1) ;
    
    cbuf_update(cb1, 2000, 1.240) ;
    cbuf_dump(cb1) ;
}

void run_main_b() {
    cbuf *cb1 ;
    
    cb1 = cbuf_init() ;
    cbuf_update(cb1, 60, 1.291) ;
    cbuf_update(cb1, 63, 1.287) ;
    cbuf_update(cb1, 63, 1.231) ;
    cbuf_update(cb1, 69, 1.229) ;
    cbuf_update(cb1, 72, 1.247) ;
    
    
    cbuf_update(cb1, 361, 1.291) ;
    
    
    cbuf_update(cb1, 411, 1.291) ;
    cbuf_update(cb1, 412, 1.281) ;
    cbuf_update(cb1, 413, 1.292) ;
    cbuf_update(cb1, 414, 1.284) ;
    cbuf_update(cb1, 414, 1.290) ;
    
    cbuf_update(cb1, 511, 1.241) ;
    cbuf_update(cb1, 512, 1.251) ;
    cbuf_update(cb1, 513, 1.232) ;
    cbuf_update(cb1, 514, 1.202) ;
    cbuf_update(cb1, 517, 1.119) ;
    
    cbuf_update(cb1, 551, 1.080) ;
    cbuf_update(cb1, 552, 1.081) ;
    cbuf_update(cb1, 553, 1.079) ;
    cbuf_update(cb1, 554, 1.088) ;
    cbuf_update(cb1, 561, 1.072) ;
    cbuf_update(cb1, 562, 1.113) ;
    cbuf_update(cb1, 563, 1.091) ;
    cbuf_update(cb1, 564, 1.092) ;
    cbuf_update(cb1, 571, 1.089) ;
    cbuf_update(cb1, 572, 1.073) ;
    cbuf_update(cb1, 573, 1.061) ;
    cbuf_update(cb1, 574, 1.111) ;
    cbuf_update(cb1, 581, 1.119) ;
    cbuf_update(cb1, 582, 1.123) ;
    cbuf_update(cb1, 583, 1.151) ;
    cbuf_update(cb1, 584, 1.153) ;
    
    cbuf_dump(cb1) ;
    
    double avg ;
    avg = cbuf_average(cb1) ;
    printf("Average rate = %f\n", avg) ;
    
    quote *q_start, *q_end ;
    q_start = cbuf_start(cb1) ;
    q_end = cbuf_end(cb1) ;
    
    printf("Start: time = %d, rate = %f\n", q_start->time, q_start->rate) ;
    printf("End:   time = %d, rate = %f\n", q_end->time, q_end->rate) ;
    
    cbuf_stats(cb1) ;
    
    cbuf_delete(cb1) ;
}

// Print out some useful data in the given circular buffer.
//
void print_data(cbuf *cb_ptr) {
    
    double avg ;
    avg = cbuf_average(cb_ptr) ;
    printf("Average rate = %f\n", avg) ;
    
    quote *q_start, *q_end ;
    q_start = cbuf_start(cb_ptr) ;
    q_end = cbuf_end(cb_ptr) ;
    
    printf("Start: time = %d, rate = %f\n", q_start->time, q_start->rate) ;
    printf("End:   time = %d, rate = %f\n", q_end->time, q_end->rate) ;
    
    return ;
}

void run_main_c() {
    cbuf *eur_usd, *eur_jpy, *usd_jpy ;
    FILE *ifile ;
    char fname[33], pair[10] ;
    unsigned int hour, min, isec, time ;
    double sec, rate ;
    int r ;
    
    eur_usd = cbuf_init() ;
    eur_jpy = cbuf_init() ;
    usd_jpy = cbuf_init() ;
    
    // Ask user for filename
    printf("File name (32 chars max): ") ;
    scanf("%32s", fname) ;
    
    // Try to open file
    ifile = fopen (fname, "r") ;
    if (ifile == NULL) {
        fprintf(stderr, "Could not open file: %s\n", fname) ;
        exit(1) ;
    }
    
    
    // keep reading file until no more ticks
    //
    while(1) {
        
        r = fscanf(ifile, "%7s %d:%d:%lf %lf", pair, &hour, &min, &sec, &rate) ;
        isec = sec ;
        
        // fprintf(stderr, "matched %d items\n", r) ;
        // fprintf(stderr, "%s, %02d:%02d:%02d %f\n", pair, hour, min, isec, rate) ;
        
        time = isec + 60 * min + 3600 * hour ;
        
        
        if (r <= 0) break ;   // EOF?
        
        if (strcmp(pair, "EUR-USD") == 0) {
            
            cbuf_update(eur_usd, time, rate) ;
            
        } else if (strcmp(pair, "EUR-JPY") == 0) {
            
            cbuf_update(eur_jpy, time, rate) ;
            
        } else if (strcmp(pair, "USD-JPY") == 0) {
            
            cbuf_update(usd_jpy, time, rate) ;
            
        } else {
            fprintf(stderr, "Not a recognized currency pair!\n") ;
        }
        
    }
    
    printf("\n\n*** Data for EUR-USD ***\n") ;
    print_data(eur_usd) ;
    cbuf_stats(eur_usd) ;
    
    printf("\n\n*** Data for EUR-JPY ***\n") ;
    print_data(eur_jpy) ;
    cbuf_stats(eur_jpy) ;
    
    printf("\n\n*** Data for USD-JPY ***\n") ;
    print_data(usd_jpy) ;
    cbuf_stats(usd_jpy) ;
    
    
    // Be nice, clean up
    cbuf_delete(eur_usd) ;
    cbuf_delete(eur_jpy) ;
    cbuf_delete(usd_jpy) ;
    fclose(ifile)  ;
}