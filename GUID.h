
#include <string>
#include <chrono>

using uint64_t = unsigned long long;

class GUID
{
private:
    static uint64_t instance_id;
    static uint64_t index;

    uint64_t head;
    uint64_t data;

public:
    static void SetInstanceID(uint64_t id)
    {
        instance_id = id;
        index = 0;
    }

    GUID()
    {
        head = 0;
        data = 0;
    }

    GUID(uint64_t head, uint64_t data)
    {
        head = head;
        this->data = data;
    }

    GUID(const GUID &xData)
    {
        head = xData.head;
        data = xData.data;
    }

    GUID(const std::string &strID)
    {
        FromString(strID);
    }

    static GUID CreateID()
    {
        int64_t value = 0;
        uint64_t time = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();

        value = time * 1000000;

        value += index++;

        if (index == 999999)
        {
            index = 0;
        }

        GUID xID;
        xID.head = instance_id;
        xID.data = value;

        return xID;
    }

    GUID &operator=(const GUID &xData)
    {
        head = xData.head;
        data = xData.data;

        return *this;
    }

    GUID &operator=(const std::string &strID)
    {
        FromString(strID);

        return *this;
    }

    const uint64_t GetHead() const
    {
        return head;
    }
    const uint64_t GetData() const
    {
        return data;
    }

    void SetHead(const uint64_t head)
    {
        this->head = head;
    }

    void SetData(const uint64_t data)
    {
        this->data = data;
    }

    bool IsValid() const
    {
        return this->head > 0;
    }

    bool operator==(const GUID &id) const
    {
        return this->data == id.data && this->head == id.head;
    }

    bool operator!=(const GUID &id) const
    {
        return this->data != id.data || this->head != id.head;
    }

    bool operator<(const GUID &id) const
    {
        if (this->head == id.head)
        {
            return this->data < id.data;
        }

        return this->head < id.head;
    }

    std::string ToString() const
    {
        return lexical_cast<std::string>(head) + "-" + lexical_cast<std::string>(data);
    }

    bool FromString(const std::string &strID)
    {
        size_t nStrLength = strID.length();
        size_t nPos = strID.find('-');
        if (nPos == std::string::npos)
        {
            return false;
        }

        std::string strHead = strID.substr(0, nPos);
        std::string strData = "";
        if (nPos + 1 < nStrLength)
        {
            strData = strID.substr(nPos + 1, nStrLength - nPos);
        }

        try
        {
            head = lexical_cast<uint64_t>(strHead);
            data = lexical_cast<uint64_t>(strData);

            return true;
        }
        catch (...)
        {
            return false;
        }
    }
};
