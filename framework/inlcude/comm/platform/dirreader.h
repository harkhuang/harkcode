
#ifndef __DIR_READER__
#define __DIR_READER__


#include <string>
#include <set>

class dir_reader {
public:

  typedef std::set<std::string>::const_iterator iterator;

  dir_reader();
  virtual ~dir_reader() {}
  
  virtual void read(const std::string& dir) = 0;
  virtual void clear();
  virtual const std::set<std::string>& files();
  virtual const std::set<std::string>& dirs();

  virtual void exclude(const std::string& spec);
  virtual void exclude(const std::set<std::string>& specs);
  virtual void include(const std::string& spec);
  virtual void include(const std::set<std::string>& specs);
  virtual void use_include(bool useinclude);
  
  static bool matches(const std::string& name, const std::string& spec);

//protected:
public:

  virtual void add_file(const std::string& file);
  virtual void add_dir(const std::string& dir);

  virtual bool is_excluded(const std::string& name) const;
  virtual bool is_include(const std::string& name) const;

private:

  std::set<std::string> m_excluded;
  std::set<std::string> m_wildcard_excluded;
  std::set<std::string> m_include;
  std::set<std::string> m_wildcard_include;

  std::set<std::string> m_files;
  std::set<std::string> m_dirs;

  bool                  m_useinclud;
};

dir_reader* new_dir_reader();

#endif
