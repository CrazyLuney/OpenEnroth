#pragma once

#include "InputStream.h"

class FileInputStream : public InputStream
{
public:
	FileInputStream() = default;
	explicit FileInputStream(std::string_view path);
	virtual ~FileInputStream();

	void open(std::string_view path);

	bool isOpen() const
	{
		return _file != nullptr;
	}

	virtual size_t read(void* data, size_t size) override;
	virtual size_t skip(size_t size) override;
	virtual void close() override;
	void seek(size_t pos);

private:
	void closeInternal(bool canThrow);

private:
	std::string _path;
	FILE* _file = nullptr;
};
