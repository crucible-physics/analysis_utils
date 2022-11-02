
#ifndef bound_mgr_hxx
#define bound_mgr_hxx

#include "common.hxx"
#include "utils.hxx"
#include "bound.hxx"

extern "C" class bound_mgr final{

  private:

    // members, config location and map, should probably be unordered set. 
    std::string bound_mgr_filename;
    std::map< std::string, bound > * bounds;

  public:
    
    // constructors
    bound_mgr(){
      bounds = new std::map< std::string, bound>();
    };
    bound_mgr( std::string bound_mgr_filename ){
      bounds = new std::map< std::string, bound>();
      this->bound_mgr_filename = bound_mgr_filename;
    };

    // prepare the manager
    void load_bound_mgr( );
    void load_bound_mgr( std::string bound_mgr_file );
    void set_bound_mgr( std::string bound_mgr_file );

    // getters
    std::string get_cut( std::string bound );
    std::vector< std::string > get_cut_series( std::string name, int bins=0 );
    std::vector< std::string > get_series_names( std::string name, int bins=0 );
    double get_width( std::string name );
    double get_bin_width( std::string name );
    bound get_bound( std::string name );
    std::string get_var( std::string name );
    int get_bins( std::string name );
    double get_min( std::string name );
    double get_max( std::string name );
    std::string get_units( std::string name );
    std::string get_ltx( std::string name );

    // setters
    void set_name( std::string name, std::string new_name );
    void set_var( std::string name, std::string var );
    void set_bins( std::string name, int bins );
    void set_min( std::string name, double min );
    void set_max( std::string name, double max );
    void set_units( std::string name, std::string units );
    void set_ltx( std::string name, std::string ltx );

    // add or modify additional bounds 
    void add_bound( std::string name );
    void add_bound( std::string name, std::string var, int bins, double min, double max );
    void add_bound( std::string name, std::string var, int bins, double min, double max, std::string units, std::string ltx );
    void set_bound( std::string name, std::string var, int bins, double min, double max );
    void set_bound( std::string name, std::string var, int bins, double min, double max, std::string units, std::string ltx );
    void process_bounds_string( std::string bounds_string );

  

};


#endif
