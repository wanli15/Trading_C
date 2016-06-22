#ifndef _WRAPPER_H_
#define _WRAPPER_H_

//Wrapper to warp data work as bridge/adaptor function
template <class T>
class Wrapper {
	T* ptr_;

public:
	Wrapper(const T & inner) {
		ptr_ = inner.clone();
	}
	Wrapper(const Wrapper & original) {
		if (original.ptr_ != 0) {
			ptr_ = original.ptr_->clone();
		}
		else {
			ptr_ = 0;
		}

	}
	~Wrapper() {
		delete ptr_;
	}
	Wrapper &operator=(const Wrapper & original) {
		if (this != &original) {
			if (ptr_ != 0) {
				delete ptr_;
				if (original.ptr_ != 0) {
					ptr_ = original.ptr_->clone();
				}
				else {
					ptr_ = 0;
				}
			}
			else {
				ptr_ = 0;
			}
		}

		return *this;
	}
	T &operator*() {
		return *ptr_;
	}
	T &operator*() const {
		return *ptr_;
	}
	T* &operator->() {
		return ptr_;
	}
	T* const &operator->() const {
		return ptr_;
	}
};


#endif /*_WRAPPER_H_*/
