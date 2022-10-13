// I have done all the coding by myself and only copied the code that
// my professor provided to complete my workshops and assignments.
// Name:   Carmen Whitton
// Email:  cwhitton@myseneca.ca
// ID#:    102710217
// Date:   10/11/2022

#ifndef SDDS_COLLECTION_H
#define SDDS_COLLECTION_H
#include <string>

namespace sdds {
   template <typename T> class Collection
   {
      std::string m_name{};
      T* m_arr{};
      size_t m_size{};
      void (*func)(const Collection<T>&, const T&);

    public:
      Collection();
      Collection(const std::string& name);
      Collection(const Collection&)            = delete;
      Collection& operator=(const Collection&) = delete;
      ~Collection();
      const std::string& name() const;
      size_t size() const;
      void setObserver(void (*observer)(const Collection<T>&, const T&));
      Collection<T>& operator+=(const T& item);
      T& operator[](size_t idx) const;
      T* operator[](const std::string& title) const;
   };
} // namespace sdds

#endif // SDDS_COLLECTION_H
