#ifndef _LAYOUTOBJECT_H_
#define _LAYOUTOBJECT_H_

#include <memory>

#define LAYOUT_DEFAULT_SPACING	(5)

namespace Framework
{
	class CLayoutBaseItem;

	class CLayoutObject
	{
	public:
								CLayoutObject(unsigned int, unsigned int);
		virtual					~CLayoutObject();

		virtual unsigned int	GetPreferredWidth()		= 0;
		virtual unsigned int	GetPreferredHeight()	= 0;
		virtual void			RefreshGeometry()		= 0;

		void					SetHorizontalStretch(unsigned int);
		void					SetVerticalStretch(unsigned int);

		unsigned int			GetHorizontalStretch()	const;
		unsigned int			GetVerticalStretch()	const;
		
		void					SetLeft(unsigned int);
		void					SetRight(unsigned int);
		void					SetTop(unsigned int);
		void					SetBottom(unsigned int);
		void					SetRect(unsigned int, unsigned int, unsigned int, unsigned int);

		unsigned int			GetLeft()		const;
		unsigned int			GetRight()		const;
		unsigned int			GetTop()		const;
		unsigned int			GetBottom()		const;

		CLayoutBaseItem*		CreateHorizontalBaseLayoutItem();
		CLayoutBaseItem*		CreateVerticalBaseLayoutItem();

	private:

		unsigned int			m_nLeft;
		unsigned int			m_nRight;
		unsigned int			m_nTop;
		unsigned int			m_nBottom;

		unsigned int			m_nHorizontalStretch;
		unsigned int			m_nVerticalStretch;
	};

    typedef std::tr1::shared_ptr<CLayoutObject> LayoutObjectPtr;
};

#endif
