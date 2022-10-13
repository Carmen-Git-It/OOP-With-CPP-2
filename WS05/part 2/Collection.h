// I have done all the coding by myself and only copied the code that
// my professor provided to complete my workshops and assignments.
// Name:   Carmen Whitton
// Email:  cwhitton@myseneca.ca
// ID#:    102710217
// Date:   10/11/2022

#ifndef SDDS_COLLECTION_H
#define SDDS_COLLECTION_H
#include <stdexcept>
#include <string>
namespace sdds {
   template <typename T> class Collection
   {
      std::string m_name{};
      T* m_arr{};
      size_t m_size{};
      void (*m_observer)(const Collection<T>&, const T&){};

    public:
      Collection() { ; }
      Collection(const std::string& name) { m_name = name; }
      Collection(const Collection&)            = delete;
      Collection& operator=(const Collection&) = delete;
      ~Collection() { delete[] m_arr; }
      const std::string& name() const { return m_name; }
      size_t size() const { return m_size; }
      void setObserver(void (*observer)(const Collection<T>&, const T&)) {
         m_observer = observer;
      }
      Collection<T>& operator+=(const T& item) {
         bool exists = false;
         for (size_t i = 0; i < m_size; i++) {
            if (m_arr[i].title().compare(item.title()) == 0) {
               exists = true;
            }
         }
         if (!exists) {

            T* temp = new T[m_size + 1];
            for (size_t i = 0; i < m_size; i++) {
               temp[i] = m_arr[i];
            }
            delete[] m_arr;
            temp[m_size] = item;
            m_arr        = temp;
            m_size++;
            if (m_observer)
               m_observer(*this, item);
         }
         return *this;
      }
      T& operator[](size_t idx) const {

         if (idx >= m_size) {
            throw std::out_of_range("Bad index [" + std::to_string(idx) +
                                    "]. Collection has [" +
                                    std::to_string(m_size) + "] items.");
         }
         return m_arr[idx];
      }
      T* operator[](const std::string& title) const {
         T* val = nullptr;
         for (size_t i = 0; i < m_size; i++) {
            if (title.compare(m_arr[i].title()) == 0) {
               val = &m_arr[i];
            }
         }
         return val;
      }
      friend std::ostream& operator<<(std::ostream& os,
                                      const Collection<T>& c) {
         for (size_t i = 0; i < c.m_size; i++) {
            os << c.m_arr[i];
         }
         return os;
      }
   };
} // namespace sdds

#endif // SDDS_COLLECTION_H
