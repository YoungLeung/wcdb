/*
 * Tencent is pleased to support the open source community by making
 * WCDB available.
 *
 * Copyright (C) 2017 THL A29 Limited, a Tencent company.
 * All rights reserved.
 *
 * Licensed under the BSD 3-Clause License (the "License"); you may not use
 * this file except in compliance with the License. You may obtain a copy of
 * the License at
 *
 *       https://opensource.org/licenses/BSD-3-Clause
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef LangSelectCore_hpp
#define LangSelectCore_hpp

#include <WINQ/lang_common.h>

namespace WCDB {

namespace lang {

class SelectCore : public Lang {
public:
    SelectCore();

    enum class Switch : int {
        NotSet,
        Select,
        Values,
    };
    Switch switcher;

    bool distinct;
    copy_on_write_lazy_lang_list<ResultColumn> resultColumns;

    enum class FromSwitch : int {
        NotSet,
        TableOrSubquery,
        JoinClause,
    };
    FromSwitch fromSwitcher;
    copy_on_write_lazy_lang_list<TableOrSubquery> tableOrSubquerys;
    copy_on_write_lazy_lang<JoinClause> joinClause;

    copy_on_write_lazy_lang<Expr> condition;

    copy_on_write_lazy_lang_list<Expr> groups;

    copy_on_write_lazy_lang<Expr> having;

    copy_on_write_lazy_lang_list<Expr> values;

    virtual copy_on_write_string SQL() const override;
};

} // namespace lang

} // namespace WCDB

#endif /* LangSelectCore_hpp */