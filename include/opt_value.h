#pragma once

#include <optional>
#include <cassert>

namespace ujos::util
{
    template<typename T, T NullValue>
    struct NullTraits
    {
        static constexpr T null_value = NullValue;

        constexpr static bool is_null(T v) noexcept
        {
            return v == NullValue;
        }

        constexpr static bool has_value(T v) noexcept
        {
            return !is_null(v);
        }
    };
}

namespace std
{
    template<typename T, T NullValue>
    class optional<ujos::util::NullTraits<T, NullValue>>
    {
    private:
        static_assert(std::is_trivially_constructible_v<T, T>);
        static_assert(std::is_nothrow_constructible_v<T, T>);
        static_assert(std::is_trivially_default_constructible_v<T>);
        static_assert(std::is_nothrow_default_constructible_v<T>);

        using traits = ujos::util::NullTraits<T, NullValue>;
        
        T value_ {traits::null_value};

    public:
        using value_type = T;

        optional() = default;

        constexpr optional(value_type value) noexcept
            : value_(value)
        {
            assert(!traits::is_null(value));
        }

        constexpr bool has_value() const noexcept
        {
            return traits::has_value(value_);
        }

        constexpr operator bool() const noexcept
        {
            return has_value();
        }

        optional& operator=(value_type value) noexcept
        {
            assert(!traits::is_null(value));

            value_ = value;

            return *this;
        }

        value_type& operator*() noexcept
        {
            assert(has_value());
            return value_;
        }

        value_type const& operator*() const noexcept
        {
            assert(has_value());
            return value_;
        }

        value_type* operator->() noexcept
        {
            assert(has_value());
            return &value_;
        }

        value_type const* operator->() const noexcept
        {
            assert(has_value());
            return &value_;
        }

        void reset() noexcept
        {
            value_ = traits::null_value;
        }

        value_type& value()
        {
            if(!has_value()) throw std::bad_optional_access();

            return value_;
        }

        value_type const& value() const
        {
            if(!has_value()) throw std::bad_optional_access();

            return value_;
        }

        void swap(optional& v2) noexcept
        {
            std::swap(value_, v2.value_);
        }

        template<class U>
        value_type value_or(U&& default_value) const noexcept
        {
            return bool(*this) ? **this : static_cast<value_type>(std::forward<U>(default_value));
        }
    };

    template<typename T, T NullValue>
    using optional_int = std::optional<ujos::util::NullTraits<T, NullValue>>;
}