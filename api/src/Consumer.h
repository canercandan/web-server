#ifndef __CONSUMER_H__
# define __CONSUMER_H__

# include <string>
# include "IRoot.h"
# include "IFlux.h"

namespace	ziApi
{
  //! Consumer
  class	Consumer : public IRoot
  {
  public:
    //! undef
    //! \param flux a IFlux pointer
    Consumer(IFlux* flux);

    //! get buffer
    //! \return std::string
    std::string	getBuf();

    //! consumer buffer
    void	consume();
    //! prepare buffer
    void	prepare();

    //! extract string in the param s_r
    void	extract(std::string& s_r);
    //! extract string in the return
    //! \return std::string
    std::string	extract();

    //! useful to consume
    void	save();
    //! useful to consume
    void	back();

    //! read a char and consume the buffer
    bool	readChar(const char c);
    //! read a char and save one in c_r
    bool	readChar(const char c, char& c_r);
    //! read a char without consuming the buffer
    bool	peekChar(const char c);

    //! read a range between c_start and c_end and consume the buffer
    bool	readRange(const char c_start, const char c_end);
    //! read a range and save one in c_r
    bool	readRange(const char c_start, const char c_end, char& c_r);
    //! read a range without consuming the buffer
    bool	peekRange(const char c, const char c_r);

    //! read a text s and consume the buffer
    bool	readText(const std::string& s);
    //! read a text and save one in s_r
    bool	readText(const std::string& s, std::string& s_r);

    //! read an integer and consume the buffer
    bool	readInteger();
    //! read an integer and save one in i_r
    bool	readInteger(int& i_r);

    //! read an identifier and consumer the buffer
    bool	readIdentifier();
    //! read an identifier and save one in s_r
    bool	readIdentifier(std::string& s_r);
  private:
    void	_appendBuf(size_t size);
  private:
    IFlux*	_flux;
    std::string	_buf;
    size_t	_ext_pos;
    size_t	_cur_pos;
    size_t	_old_pos;
  };
};

#endif // !__CONSUMER_H__
